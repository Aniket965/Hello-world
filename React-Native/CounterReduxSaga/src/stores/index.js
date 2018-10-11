import { createStore, combineReducers, applyMiddleware } from 'redux';
import { HomeReducer } from '../features/home/home.reducer';
import createSagaMiddeware from 'redux-saga';
import rootSaga from './saga/index';

const sagaMiddleware = createSagaMiddeware();

const store = createStore(
  combineReducers({ home: HomeReducer }),
  applyMiddleware(sagaMiddleware)
);

sagaMiddleware.run(rootSaga);

export default store;
