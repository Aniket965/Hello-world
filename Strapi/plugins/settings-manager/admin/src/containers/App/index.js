/**
 *
 * This component is the skeleton around the actual pages, and should only
 * contain code that should be seen on all pages. (e.g. navigation bar)
 *
 */

import React from 'react';
import PropTypes from 'prop-types';
import { connect } from 'react-redux';
import { createStructuredSelector } from 'reselect';
import { bindActionCreators, compose } from 'redux';
import 'flag-icon-css/css/flag-icon.css';
import 'react-select/dist/react-select.css';
import { Switch, Route } from 'react-router-dom';
import { isEmpty } from 'lodash';
import { pluginId } from 'app';

import injectSaga from 'utils/injectSaga';

import HomePage from 'containers/HomePage';

import { menuFetch, environmentsFetch } from './actions';
import { makeSelectLoading, makeSelectSections } from './selectors';
import styles from './styles.scss';

import saga from './sagas';

/* eslint-disable react/require-default-props  */
class App extends React.Component {
  componentDidMount() {
    this.props.menuFetch();
    this.props.environmentsFetch();
  }

  componentWillUpdate(nextProps) {
    if (!isEmpty(nextProps.sections) && nextProps.location.pathname !== '/plugins/settings-manager') {
      const allowedPaths = nextProps.sections.reduce((acc, current) => {
        const slugs = current.items.reduce((acc, current) => {
          acc.push(current.slug);

          return acc;
        }, []);
        return acc.concat(slugs);
      }, []);

      const slug = nextProps.location.pathname.split('/')[3];
      const shouldRedirect = allowedPaths.filter(el => el === slug).length === 0;

      if (shouldRedirect) {
        this.props.history.push('/404');
      }
    }
  }

  render() {
    return (
      <div className={`${pluginId} ${styles.app}`}>
        <Switch>
          <Route path="/plugins/settings-manager/:slug/:env" component={HomePage} />
          <Route path="/plugins/settings-manager/:slug" component={HomePage} />
          <Route path="/plugins/settings-manager" component={HomePage} />
        </Switch>
      </div>
    );
  }
}

App.contextTypes = {
  router: PropTypes.object.isRequired,
};

App.propTypes = {
  environmentsFetch: PropTypes.func.isRequired,
  history: PropTypes.object.isRequired,
  menuFetch: PropTypes.func.isRequired,
  sections: PropTypes.array.isRequired,
};

export function mapDispatchToProps(dispatch) {
  return bindActionCreators(
    {
      menuFetch,
      environmentsFetch,
    },
    dispatch
  );
}

const mapStateToProps = createStructuredSelector({
  loading: makeSelectLoading(),
  sections: makeSelectSections(),
});

// Wrap the component to inject dispatch and state into it
const withConnect = connect(mapStateToProps, mapDispatchToProps);

const withSaga = injectSaga({ key: 'global', saga });

export default compose(
  withSaga,
  withConnect,
)(App);
