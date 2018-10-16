import { takeEvery, take, put } from 'redux-saga/effects';
import HomeTypes from '../../features/home/home.types';

function* incrementSaga() {
  console.log('inc ===>');
}

function* decrementSaga() {
  console.log('dec ===>');
}

function* applyNumber(action) {
  console.log('applyNumber ===>');
  yield put({ type: HomeTypes.HOME_APPLYNUMBER, number: action.number });
}

function* rootSaga() {
  yield takeEvery(HomeTypes.HOME_INCREMENT, incrementSaga);
  yield takeEvery(HomeTypes.HOME_DECREMENT, decrementSaga);
  yield takeEvery(HomeTypes.HOME_SETNUMBER, applyNumber);
  yield take(HomeTypes.HOME_RESET);
}

export default rootSaga;