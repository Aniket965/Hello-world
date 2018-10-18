import { LOCATION_CHANGE } from 'react-router-redux';
import { findIndex, get, isArray, isEmpty,   isNumber, isString, map } from 'lodash';
import {
  call,
  cancel,
  fork,
  put,
  select,
  take,
  takeLatest,
} from 'redux-saga/effects';

// Utils.
import cleanData from 'utils/cleanData';
import request from 'utils/request';
import templateObject from 'utils/templateObject';

import {
  getDataSucceeded,
  getLayoutSucceeded,
  setFormErrors,
  setLoader,
  submitSuccess,
  unsetLoader,
} from './actions';
import { GET_DATA, GET_LAYOUT, SUBMIT } from './constants';
import {
  makeSelectFileRelations,
  makeSelectIsCreating,
  makeSelectModelName,
  makeSelectRecord,
  makeSelectSource,
} from './selectors';

function* dataGet(action) {
  try {
    const modelName = yield select(makeSelectModelName());
    const params = { source: action.source };
    const [response, layout] = yield [
      call(request, `/content-manager/explorer/${modelName}/${action.id}`, { method: 'GET', params }),
      call(request, '/content-manager/layout', { method: 'GET', params }),
    ];
    const pluginHeaderTitle = yield call(templateObject, { mainField: action.mainField }, response);
    yield put(getDataSucceeded(action.id, response, pluginHeaderTitle.mainField));
    yield put(getLayoutSucceeded(layout));
  } catch(err) {
    strapi.notification.error('content-manager.error.record.fetch');
  }
}

function* layoutGet(action) {
  try {
    const params = { source: action.source };
    const response = yield call(request, '/content-manager/layout', { method: 'GET', params });
    yield put(getLayoutSucceeded(response));
  } catch(err) {
    strapi.notification('notification.error');
  }
}

export function* submit() {
  const currentModelName = yield select(makeSelectModelName());
  const fileRelations = yield select(makeSelectFileRelations());
  const isCreating = yield select(makeSelectIsCreating());
  const record = yield select(makeSelectRecord());
  const source = yield select(makeSelectSource());

  try {
    // Show button loader
    yield put(setLoader());
    const recordCleaned = Object.keys(record).reduce((acc, current) => {
      const cleanedData = cleanData(record[current], 'value', 'id');

      if (isString(cleanedData) || isNumber(cleanedData)) {
        acc.append(current, cleanedData);
      } else if (findIndex(fileRelations, ['name', current]) !== -1) {
        // Don't stringify the file
        map(record[current], (file) => {
          if (file instanceof File) {
            return acc.append(current, file);
          }

          return acc.append(current, JSON.stringify(file));
        });

        if (isEmpty(record[current])) {
          // Send an empty array if relation is manyToManyMorph else an object
          const data = get(fileRelations, [findIndex(fileRelations, ['name', current]), 'multiple']) ? [] : {};
          acc.append(current, JSON.stringify(data));
        }
      } else {
        acc.append(current, JSON.stringify(cleanedData));
      }

      return acc;
    }, new FormData());

    const id = isCreating ? '' : record.id || record._id;
    const params = { source };
    // Change the request helper default headers so we can pass a FormData
    const headers = {
      'X-Forwarded-Host': 'strapi',
    };

    const requestUrl = `/content-manager/explorer/${currentModelName}/${id}`;

    // Call our request helper (see 'utils/request')
    // Pass false and false as arguments so the request helper doesn't stringify
    // the body and doesn't watch for the server to restart
    yield call(request, requestUrl, {
      method: isCreating ? 'POST' : 'PUT',
      headers,
      body: recordCleaned,
      params,
    }, false, false);

    strapi.notification.success('content-manager.success.record.save');
    // Redirect the user to the ListPage container
    yield put(submitSuccess());

  } catch(err) {
    if (isArray(err.response.payload.message)) {
      const errors = err.response.payload.message.reduce((acc, current) => {
        const error = current.messages.reduce((acc, current) => {
          acc.errorMessage = current.id;

          return acc;
        }, { id: 'components.Input.error.custom-error', errorMessage: '' });
        acc.push(error);

        return acc;
      }, []);

      const name = get(err.response.payload.message, ['0', 'messages', '0', 'field']);

      yield put(setFormErrors([{ name, errors }]));
    }
    strapi.notification.error(isCreating ? 'content-manager.error.record.create' : 'content-manager.error.record.update');
  } finally {
    yield put(unsetLoader());
  }
}

function* defaultSaga() {
  const loadDataWatcher = yield fork(takeLatest, GET_DATA, dataGet);
  yield fork(takeLatest, GET_LAYOUT, layoutGet);
  yield fork(takeLatest, SUBMIT, submit);

  yield take(LOCATION_CHANGE);

  yield cancel(loadDataWatcher);
}

export default defaultSaga;
