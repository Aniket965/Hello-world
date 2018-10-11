import React from 'react';
import { Provider } from 'react-redux';
import store from './stores/index';

import HomeComponent from './features/home/home.component';

export default () => (
  <Provider store={store}>
    <HomeComponent />
  </Provider>
);
