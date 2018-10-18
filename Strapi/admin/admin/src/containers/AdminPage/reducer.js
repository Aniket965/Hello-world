/**
 *
 * AdminPage reducer
 *
 */

import { fromJS, Map } from 'immutable';

import {
  GET_GA_STATUS_SUCCEEDED,
  GET_LAYOUT_SUCCEEDED,
  GET_STRAPI_VERSION_SUCCEEDED,
} from './constants';

const initialState = fromJS({
  allowGa: true,
  layout: Map({}),
  strapiVersion: '3',
});

function adminPageReducer(state = initialState, action) {
  switch (action.type) {
    case GET_GA_STATUS_SUCCEEDED:
      return state.update('allowGa', () => action.allowGa);
    case GET_LAYOUT_SUCCEEDED:
      return state.update('layout', () => Map(action.layout));
    case GET_STRAPI_VERSION_SUCCEEDED:
      return state.update('strapiVersion', () => action.strapiVersion);
    default:
      return state;
  }
}

export default adminPageReducer;
