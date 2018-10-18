/**
 *
 * EditPage
 *
 */

import React from 'react';
import PropTypes from 'prop-types';
import { connect } from 'react-redux';
import { createStructuredSelector } from 'reselect';
import { bindActionCreators, compose } from 'redux';
import { FormattedMessage } from 'react-intl';
import { findIndex, get, isEmpty, isEqual, size } from 'lodash';
import cn from 'classnames';

// Design
import BackHeader from 'components/BackHeader';
import Input from 'components/InputsIndex';
import InputSearch from 'components/InputSearchContainer';
import PluginHeader from 'components/PluginHeader';
import Plugins from 'components/Plugins';
import Policies from 'components/Policies';

import injectSaga from 'utils/injectSaga';
import injectReducer from 'utils/injectReducer';

// Actions
import {
  addUser,
  getPermissions,
  getPolicies,
  getRole,
  getUser,
  onCancel,
  onChangeInput,
  onClickAdd,
  onClickDelete,
  selectAllActions,
  setActionType,
  setErrors,
  setForm,
  setInputPoliciesPath,
  setRoleId,
  setShouldDisplayPolicieshint,
  submit,
  resetShouldDisplayPoliciesHint,
} from './actions';

// Selectors
import makeSelectEditPage from './selectors';

import reducer from './reducer';
import saga from './saga';

import styles from './styles.scss';

export class EditPage extends React.Component { // eslint-disable-line react/prefer-stateless-function
  getChildContext = () => (
    {
      onChange: this.props.onChangeInput,
      selectAllActions: this.props.selectAllActions,
      setInputPoliciesPath: this.props.setInputPoliciesPath,
      setShouldDisplayPolicieshint: this.props.setShouldDisplayPolicieshint,
      resetShouldDisplayPoliciesHint: this.props.resetShouldDisplayPoliciesHint,
    }
  );

  componentDidMount() {
    this.props.setActionType(this.props.match.params.actionType);
    this.props.getPolicies();

    if (this.props.match.params.actionType === 'create') {
      // Set reducer modifiedData
      this.props.setForm();
      // Get the available permissions
      this.props.getPermissions();
    } else {
      this.props.setRoleId(this.props.match.params.id);
      this.props.getRole(this.props.match.params.id);
    }
  }

  componentWillReceiveProps(nextProps) {
    // Redirect user to HomePage if submit ok
    if (nextProps.editPage.didSubmit !== this.props.editPage.didSubmit) {
      this.props.history.push('/plugins/users-permissions/roles');
    }
  }

  componentWillUnmount() {
    // Empty formErrors
    this.props.setErrors([]);
    this.props.resetShouldDisplayPoliciesHint();
  }

  handleSubmit = () => {
    // Check if the name field is filled
    if (isEmpty(get(this.props.editPage, ['modifiedData', 'name']))) {
      return this.props.setErrors([{ name: 'name', errors: [{ id: 'users-permissions.EditPage.form.roles.name.error' }] }]);
    }

    this.props.submit();
  }

  render() {
    const pluginHeaderTitle = this.props.match.params.actionType === 'create' ?
      'users-permissions.EditPage.header.title.create'
      : 'users-permissions.EditPage.header.title';
    const pluginHeaderDescription = this.props.match.params.actionType === 'create' ?
      'users-permissions.EditPage.header.description.create'
      : 'users-permissions.EditPage.header.description';
    const pluginHeaderActions = [
      {
        label: 'users-permissions.EditPage.cancel',
        kind: 'secondary',
        onClick: this.props.onCancel,
        type: 'button',
      },
      {
        kind: 'primary',
        label: 'users-permissions.EditPage.submit',
        onClick: this.handleSubmit,
        type: 'submit',
        disabled: isEqual(this.props.editPage.modifiedData, this.props.editPage.initialData),
      },
    ];

    return (
      <div>
        <BackHeader onClick={() => this.props.history.goBack()} />
        <div className={cn('container-fluid', styles.containerFluid)}>
          <PluginHeader
            title={{
              id: pluginHeaderTitle,
              values: {
                name: get(this.props.editPage.initialData, 'name'),
              },
            }}
            description={{
              id: pluginHeaderDescription,
              values: {
                description: get(this.props.editPage.initialData, 'description') || '',
              },
            }}
            actions={pluginHeaderActions}
          />
          <div className={cn('row', styles.container)}>
            <div className="col-md-12">
              <div className={styles.main_wrapper}>
                <div className={styles.titleContainer}>
                  <FormattedMessage id="users-permissions.EditPage.form.roles" />
                </div>
                <form className={styles.form}>
                  <div className="row">
                    <div className="col-md-6">
                      <div className="row">
                        <Input
                          autoFocus
                          customBootstrapClass="col-md-12"
                          errors={get(this.props.editPage, ['formErrors', findIndex(this.props.editPage.formErrors, ['name', 'name']), 'errors'])}
                          didCheckErrors={this.props.editPage.didCheckErrors}
                          label={{ id: 'users-permissions.EditPage.form.roles.label.name' }}
                          name="name"
                          onChange={this.props.onChangeInput}
                          type="text"
                          validations={{ required: true }}
                          value={get(this.props.editPage, ['modifiedData', 'name'])}
                        />
                      </div>
                      <div className="row">
                        <Input
                          customBootstrapClass="col-md-12"
                          label={{ id: 'users-permissions.EditPage.form.roles.label.description' }}
                          name="description"
                          onChange={this.props.onChangeInput}
                          type="textarea"
                          validations={{ required: true }}
                          value={get(this.props.editPage, ['modifiedData', 'description'])}
                        />
                      </div>
                    </div>
                    <InputSearch
                      addUser={this.props.addUser}
                      didDeleteUser={this.props.editPage.didDeleteUser}
                      didFetchUsers={this.props.editPage.didFetchUsers}
                      didGetUsers={this.props.editPage.didGetUsers}
                      getUser={this.props.getUser}
                      label={{
                        id: 'users-permissions.EditPage.form.roles.label.users',
                        params: {
                          number: size(get(this.props.editPage, ['modifiedData', 'users'])),
                        },
                      }}
                      onClickAdd={this.props.onClickAdd}
                      onClickDelete={this.props.onClickDelete}
                      name="users"
                      type="text"
                      users={get(this.props.editPage, 'users')}
                      validations={{ required: true }}
                      values={get(this.props.editPage, ['modifiedData', 'users'])}
                    />
                    <div className="col-md-12">
                      <div className={styles.separator} />
                    </div>
                  </div>
                  <div className="row" style={{ marginRight: '-30px'}}>
                    <Plugins
                      plugins={get(this.props.editPage, ['modifiedData', 'permissions'])}
                    />
                    <Policies
                      shouldDisplayPoliciesHint={this.props.editPage.shouldDisplayPoliciesHint}
                      inputSelectName={this.props.editPage.inputPoliciesPath}
                      routes={this.props.editPage.routes}
                      selectOptions={this.props.editPage.policies}
                      values={this.props.editPage.modifiedData}
                    />
                  </div>
                </form>
              </div>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

EditPage.childContextTypes = {
  onChange: PropTypes.func.isRequired,
  selectAllActions: PropTypes.func.isRequired,
  setInputPoliciesPath: PropTypes.func.isRequired,
  setShouldDisplayPolicieshint: PropTypes.func.isRequired,
  resetShouldDisplayPoliciesHint: PropTypes.func.isRequired,
};

EditPage.propTypes = {
  addUser: PropTypes.func.isRequired,
  editPage: PropTypes.object.isRequired,
  getPermissions: PropTypes.func.isRequired,
  getPolicies: PropTypes.func.isRequired,
  getRole: PropTypes.func.isRequired,
  getUser: PropTypes.func.isRequired,
  history: PropTypes.object.isRequired,
  match: PropTypes.object.isRequired,
  onCancel: PropTypes.func.isRequired,
  onChangeInput: PropTypes.func.isRequired,
  onClickAdd: PropTypes.func.isRequired,
  onClickDelete: PropTypes.func.isRequired,
  resetShouldDisplayPoliciesHint: PropTypes.func.isRequired,
  selectAllActions: PropTypes.func.isRequired,
  setActionType: PropTypes.func.isRequired,
  setErrors: PropTypes.func.isRequired,
  setForm: PropTypes.func.isRequired,
  setInputPoliciesPath: PropTypes.func.isRequired,
  setRoleId: PropTypes.func.isRequired,
  setShouldDisplayPolicieshint: PropTypes.func.isRequired,
  submit: PropTypes.func.isRequired,
};

const mapStateToProps = createStructuredSelector({
  editPage: makeSelectEditPage(),
});

function mapDispatchToProps(dispatch) {
  return bindActionCreators(
    {
      addUser,
      getPermissions,
      getPolicies,
      getRole,
      getUser,
      onCancel,
      onChangeInput,
      onClickAdd,
      onClickDelete,
      selectAllActions,
      setActionType,
      setErrors,
      setForm,
      setInputPoliciesPath,
      setRoleId,
      setShouldDisplayPolicieshint,
      submit,
      resetShouldDisplayPoliciesHint,
    },
    dispatch,
  );
}

const withConnect = connect(mapStateToProps, mapDispatchToProps);

/* Remove this line if the container doesn't have a route and
*  check the documentation to see how to create the container's store
*/
const withReducer = injectReducer({ key: 'editPage', reducer });

/* Remove the line below the container doesn't have a route and
*  check the documentation to see how to create the container's store
*/
const withSaga = injectSaga({ key: 'editPage', saga });

export default compose(
  withReducer,
  withSaga,
  withConnect,
)(EditPage);
