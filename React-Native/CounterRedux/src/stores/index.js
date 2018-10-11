import { createStore, combineReducers } from 'redux';
import { HomeReducer } from '../features/home/home.reducer';

const store = createStore(
  combineReducers({ home: HomeReducer }),
);

export default store;

