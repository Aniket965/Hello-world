/*
 *
 * HomePage
 *
 */

import React from 'react';
import PropTypes from 'prop-types';
import { connect } from 'react-redux';
import { createStructuredSelector } from 'reselect';
import { injectIntl } from 'react-intl';
import { bindActionCreators, compose } from 'redux';

import injectReducer from 'utils/injectReducer';
import injectSaga from 'utils/injectSaga';

// Selectors
import selectHomePage from './selectors';

import reducer from './reducer';
import saga from './saga';

export class HomePage extends React.Component {
  render() {
    const { innerHeight } = window;
    // TODO change iframe URL
    return (
      <iframe src="https://marketplace.strapi.io/analytics" style={{ width: '100%', height: `${innerHeight - 100}px`, border: '0' }}  frameBorder="0" scrolling="no" title="analytics" />
    );
  }
}

HomePage.contextTypes = {
  router: PropTypes.object,
};

HomePage.propTypes = {
  // homePage: PropTypes.object,
};

function mapDispatchToProps(dispatch) {
  return bindActionCreators(
    {
      // Your actions here
    },
    dispatch,
  );
}

const mapStateToProps = createStructuredSelector({
  homePage: selectHomePage(),
});

const withConnect = connect(mapStateToProps, mapDispatchToProps);

const withReducer = injectReducer({ key: 'homePage', reducer });
const withSaga = injectSaga({ key: 'homePage', saga });

export default compose(
  withReducer,
  withSaga,
  withConnect,
)(injectIntl(HomePage));
