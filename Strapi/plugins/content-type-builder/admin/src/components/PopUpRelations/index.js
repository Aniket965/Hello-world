/**
*
* PopUpRelations
*
*/

import React from 'react';
import PropTypes from 'prop-types';
import { findIndex, get, isEmpty, map, take, takeRight } from 'lodash';
import { FormattedMessage } from 'react-intl';

import { Button, Modal, ModalHeader, ModalBody, ModalFooter } from 'reactstrap';
import Input from 'components/InputsIndex';
import PopUpHeaderNavLink from 'components/PopUpHeaderNavLink';
import RelationBox from 'components/RelationBox';
import RelationNaturePicker from 'components/RelationNaturePicker';
import styles from './styles.scss';

/* eslint-disable jsx-a11y/tabindex-no-positive */
class PopUpRelations extends React.Component { // eslint-disable-line react/prefer-stateless-function
  constructor(props) {
    super(props);
    this.popUpHeaderNavLinks = [
      { name: 'defineRelation', message: 'content-type-builder.popUpForm.navContainer.relation', nameToReplace: 'advancedSettings' },
      { name: 'advancedSettings', message: 'content-type-builder.popUpForm.navContainer.advanced', nameToReplace: 'defineRelation' },
    ];
  }

  componentDidMount() {
    if (!isEmpty(this.props.dropDownItems) && !this.props.isEditting) {
      this.init(this.props);
    }
  }

  componentWillReceiveProps(nextProps) {
    if (isEmpty(this.props.dropDownItems) && !isEmpty(nextProps.dropDownItems) && !this.props.isEditting) {
      this.init(nextProps);
    }
  }

  init = (props) => {
    const target = {
      name: 'params.target',
      type: 'string',
      value: get(props.dropDownItems[0], 'name'),
    };

    this.props.onChange({ target });

    if (get(props.dropDownItems[0], 'source')) {
      this.props.onChange({
        target: {
          type: 'string',
          name: 'params.pluginValue',
          value: get(props.dropDownItems[0], 'source'),
        },
      });
    }
  }

  renderNavContainer = () => (
    <div className={styles.navContainer}>
      {map(this.popUpHeaderNavLinks, (link, key) => (
        <PopUpHeaderNavLink
          key={key}
          message={link.message}
          name={link.name}
          nameToReplace={link.nameToReplace}
          routePath={this.props.routePath}
        />
      ))}
    </div>
  )

  renderModalBodyAdvanced = () => (
    <ModalBody className={`${styles.modalBodyAdvanced}`}>
      <div className="container-fluid">
        <div className="row">
          {map(take(this.props.form.items, 1), (input, key) => (
            <Input
              key={key}
              customBootstrapClass="col-md-6 offset-md-6 mr-md-5"
              type={input.type}
              value={get(this.props.values, ['params', input.name.split('.')[1]])}
              name={input.name}
              label={input.label}
              title={input.title}
              validations={input.validations}
              inputDescription={input.inputDescription}
              {...this.props}
            />
          ))}
          <div className={styles.divider} />
        </div>
        <div className={styles.inputContainer}>
          <div className="row">
            {map(takeRight(this.props.form.items, 2), (value, index) => {
              const addon = index === 0 ? get(this.props.values, 'name') : get(this.props.values, ['params', 'key']);
              return (
                <Input
                  key={index}
                  type={value.type}
                  value={get(this.props.values, ['params', value.name.split('.')[1]])}
                  name={value.name}
                  label={value.label}
                  title={value.title}
                  validations={value.validations}
                  inputDescription={value.inputDescription}
                  {...this.props}
                  addon={addon}
                  placeholder=" "
                  disabled={isEmpty(addon)}
                />
              );
            })}
          </div>
        </div>
      </div>
    </ModalBody>
  )

  renderModalBodyRelations = () => {
    const header = get(this.props.values, ['params', 'pluginValue']) ?
      get(this.props.dropDownItems, [findIndex(this.props.dropDownItems, {'name': get(this.props.values, ['params', 'target']), source: get(this.props.values, ['params', 'pluginValue']) })])
      : get(this.props.dropDownItems, [findIndex(this.props.dropDownItems, ['name', get(this.props.values, ['params', 'target'])])]);

    return (
      <ModalBody className={`${styles.modalBody} ${styles.flex}`}>
        <RelationBox
          autoFocus
          tabIndex="1"
          relationType={get(this.props.values, ['params', 'nature'])}
          contentTypeTargetPlaceholder={get(this.props.values, ['params', 'target'])}
          isFirstContentType
          header={this.props.contentType}
          input={get(this.props.form, ['items', '0'])}
          value={get(this.props.values, 'name')}
          onSubmit={this.props.onSubmit}
          onChange={this.props.onChange}
          didCheckErrors={this.props.didCheckErrors}
          errors={findIndex(this.props.formErrors, ['name', get(this.props.form, ['items', '0', 'name'])]) !== -1 ? this.props.formErrors[findIndex(this.props.formErrors, ['name', get(this.props.form, ['items', '0', 'name'])])].errors : []}
        />
        <RelationNaturePicker
          selectedIco={get(this.props.values, ['params', 'nature'])}
          onChange={this.props.onChange}
          contentTypeName={get(this.props.contentType, 'name')}
          contentTypeTarget={get(this.props.values, ['params', 'target'])}
        />
        <RelationBox
          tabIndex="2"
          contentTypeTargetPlaceholder={get(this.props.contentType, 'name')}
          relationType={get(this.props.values, ['params', 'nature'])}
          onSubmit={this.props.onSubmit}
          header={header}
          input={get(this.props.form, ['items', '1'])}
          value={get(this.props.values, ['params', 'key'])}
          onChange={this.props.onChange}
          didCheckErrors={this.props.didCheckErrors}
          errors={findIndex(this.props.formErrors, ['name', get(this.props.form, ['items', '1', 'name'])]) !== -1 ? this.props.formErrors[findIndex(this.props.formErrors, ['name', get(this.props.form, ['items', '1', 'name'])])].errors : []}
          dropDownItems={this.props.dropDownItems}
        />
      </ModalBody>
    );
  }

  render() {
    const loader = this.props.showLoader ?
      <Button onClick={this.props.onSubmit} type="submit" className={styles.primary} disabled={this.props.showLoader}><p className={styles.saving}><span>.</span><span>.</span><span>.</span></p></Button>
      : <Button type="submit" onClick={this.props.onSubmit} className={styles.primary}><FormattedMessage id="content-type-builder.form.button.continue" /></Button>;

    const modalBody = this.props.showRelation ? this.renderModalBodyRelations():  this.renderModalBodyAdvanced();
    const handleToggle = this.props.toggle;

    return (
      <div className={styles.popUpRelations}>
        <Modal isOpen={this.props.isOpen} toggle={this.props.toggle} className={`${styles.modalPosition}`}>
          <ModalHeader toggle={this.props.toggle} className={styles.popUpFormHeader} />
          <div className={styles.headerContainer}>
            <div className={styles.titleContainer}>
              <div>
                <FormattedMessage id={this.props.popUpTitle} />
                &nbsp;
                <FormattedMessage id="content-type-builder.popUpRelation.title" />
              </div>
            </div>

            {this.renderNavContainer()}
          </div>

          {modalBody}

          <ModalFooter className={styles.modalFooter}>
            <Button onClick={handleToggle} className={styles.secondary}><FormattedMessage id="content-type-builder.form.button.cancel" /></Button>
            {loader}{' '}
          </ModalFooter>
        </Modal>
      </div>
    );
  }
}

PopUpRelations.propTypes = {
  contentType: PropTypes.object,
  didCheckErrors: PropTypes.bool.isRequired,
  dropDownItems: PropTypes.array,
  form: PropTypes.oneOfType([
    PropTypes.array.isRequired,
    PropTypes.object.isRequired,
  ]).isRequired,
  formErrors: PropTypes.oneOfType([
    PropTypes.array,
    PropTypes.object,
  ]).isRequired,
  isEditting: PropTypes.bool,
  isOpen: PropTypes.bool.isRequired,
  onChange: PropTypes.func.isRequired,
  onSubmit: PropTypes.func.isRequired,
  popUpTitle: PropTypes.string.isRequired,
  routePath: PropTypes.string.isRequired,
  showLoader: PropTypes.bool,
  showRelation: PropTypes.bool.isRequired,
  toggle: PropTypes.func.isRequired,
  values: PropTypes.object,
};

PopUpRelations.defaultProps = {
  contentType: {},
  dropDownItems: [],
  isEditting: false,
  showLoader: false,
  values: {},
};

export default PopUpRelations;
