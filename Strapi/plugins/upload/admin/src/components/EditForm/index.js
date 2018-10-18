/**
 *
 * EditForm
 *
 */

import React from 'react';
import { findIndex, get, isEmpty, map } from 'lodash';
import PropTypes from 'prop-types';
// You can find these components in either
// ./node_modules/strapi-helper-plugin/lib/src
// or strapi/packages/strapi-helper-plugin/lib/src
import Input from 'components/InputsIndex';

import styles from './styles.scss';

class EditForm extends React.Component  {
  getProviderForm = () => get(this.props.settings, ['providers', this.props.selectedProviderIndex, 'auth'], {});

  generateSelectOptions = () => (
    Object.keys(get(this.props.settings, 'providers', {})).reduce((acc, current) => {
      const option = {
        id: get(this.props.settings, ['providers', current, 'name']),
        value: get(this.props.settings, ['providers', current, 'provider']),
      };
      acc.push(option);
      return acc;
    }, [])
  )

  render() {
    return (
      <div className={styles.editForm}>
        <div className="row">
          <Input
            customBootstrapClass="col-md-6"
            inputDescription={{ id: 'upload.EditForm.Input.select.inputDescription' }}
            inputClassName={styles.inputStyle}
            label={{ id: 'upload.EditForm.Input.select.label' }}
            name="provider"
            onChange={this.props.onChange}
            selectOptions={this.generateSelectOptions()}
            type="select"
            value={get(this.props.modifiedData, 'provider')}
          />
        </div>
        {!isEmpty(this.getProviderForm()) && (
          <div className={styles.subFormWrapper}>
            <div className="row">
              {map(this.getProviderForm(), (value, key) => (
                <Input
                  didCheckErrors={this.props.didCheckErrors}
                  errors={get(this.props.formErrors, [findIndex(this.props.formErrors, ['name', key]), 'errors'])}
                  key={key}
                  label={{ id: value.label }}
                  name={key}
                  onChange={this.props.onChange}
                  selectOptions={value.values}
                  type={value.type === 'enum' ? 'select' : value.type}
                  validations={{ required: true }}
                  value={get(this.props.modifiedData, key, '')}
                />
              ))}
            </div>
          </div>
        )}
        <div className={styles.separator} />
        <div className="row">
          <Input
            inputClassName={styles.inputStyle}
            label={{ id: 'upload.EditForm.Input.number.label' }}
            name="sizeLimit"
            onChange={this.props.onChange}
            type="number"
            value={get(this.props.modifiedData, 'sizeLimit', 1) / 1000}
          />
        </div>
        <div className={styles.separator} style={{ marginTop: '-4px'}} />
        <div className="row">
          <Input
            label={{ id: 'upload.EditForm.Input.toggle.label' }}
            name="enabled"
            onChange={this.props.onChange}
            type="toggle"
            value={get(this.props.modifiedData, 'enabled', false)}
          />
        </div>
      </div>
    );
  }
}

EditForm.defaultProps = {
  settings: {
    providers: [],
  },
};

EditForm.propTypes = {
  didCheckErrors: PropTypes.bool.isRequired,
  formErrors: PropTypes.array.isRequired,
  modifiedData: PropTypes.object.isRequired,
  onChange: PropTypes.func.isRequired,
  selectedProviderIndex: PropTypes.number.isRequired,
  settings: PropTypes.object,
};

export default EditForm;
