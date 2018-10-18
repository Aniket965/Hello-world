/**
*
* RowDatabase
*
*/

import React from 'react';
import PropTypes from 'prop-types';
import { FormattedMessage } from 'react-intl';

// modal
import { Button, Modal, ModalHeader, ModalBody, ModalFooter } from 'reactstrap';
import PopUpForm from 'components/PopUpForm';
import PopUpWarning from 'components/PopUpWarning';
import styles from 'components/List/styles.scss';

/* eslint-disable react/require-default-props  */
class RowDatabase extends React.Component { // eslint-disable-line react/prefer-stateless-function
  constructor(props) {
    super(props);
    this.state = {
      modal: false,
      warning: false,
      loader: false,
    };
  }

  deleteDatabase = () => {
    this.setState({ warning: !this.state.warning });
    this.props.onDeleteDatabase(this.props.data.name);
  }

  handleShowDatabaseModal = (e) => {
    if (e.target.id !== 'trash') {
      this.setState({ modal: !this.state.modal });
      this.props.getDatabase(this.props.data.name);
    }
  }

  handleSubmit = (e) => {
    e.preventDefault();
    this.setState({ modal: false });
    this.props.onSubmit(this.props.data.name);
  }

  handleToggle = () => {
    this.setState({ modal: !this.state.modal });
  }

  handleToggleWarning = () => this.setState({ warning: !this.state.warning });

  toggle = () => {
    this.setState({ modal: !this.state.modal });
  }

  toggleWarning = () => this.setState({ warning: !this.state.warning });

  render() {
    const content = {
      message: this.props.data.isUsed ? 'settings-manager.popUpWarning.databases.danger.message' : 'settings-manager.popUpWarning.databases.delete.message',
      confirm: this.props.data.isUsed ? 'settings-manager.popUpWarning.danger.ok.message' : '',
    };
    const loader = this.state.loader
      ? <Button onClick={this.handleSubmit} className={styles.primary} disabled={this.state.loader}><p className={styles.saving}><span>.</span><span>.</span><span>.</span></p></Button>
      : (
        <FormattedMessage id="settings-manager.form.button.save">
          {(message) => (
            <Button onClick={this.handleSubmit} className={styles.primary}>{message}</Button>
          )}
        </FormattedMessage>
      );

    return (
      <li className={`${styles.databaseFont}`} style={{ cursor: 'pointer'}} onClick={this.handleShowDatabaseModal}>
        <div className={styles.flexLi}>
          <div className={styles.flexed}>
            <div className={styles.squared} style={{ backgroundColor: this.props.data.color }}>
              {this.props.data.letter}
            </div>
            <div className={styles.label} style={{ fontWeight: '500'}}>{this.props.data.name}</div>
          </div>
          <div className={styles.dbHost}>
            {this.props.data.host}
          </div>
          <div className={styles.centered} style={{ width: '15rem'}}>{this.props.data.database}</div>
          <div className={styles.flexed} style={{ minWidth: '3rem', justifyContent: 'space-between'}}>
            <div className={styles.ico}><i className="fa fa-pencil" id={this.props.data.name} /></div>
            <div className={`${styles.leftSpaced} ${styles.ico}`}><i id="trash" className="fa fa-trash" onClick={this.handleToggleWarning} /></div>
          </div>
        </div>
        <div>
          <Modal isOpen={this.state.modal} toggle={this.toggle} className={styles.modalPosition}>
            <ModalHeader toggle={this.toggle} className={`${styles.noBorder} ${styles.padded} ${styles.mHeader}`}>
              Databases
            </ModalHeader>
            <div className={styles.bordered} />
            <form autoComplete="off">
              <ModalBody className={styles.modalBody}>
                <div className={styles.spacerSmall} />
                <PopUpForm {...this.props} />
              </ModalBody>
              <ModalFooter className={`${styles.noBorder} ${styles.modalFooter}`}>
                <FormattedMessage id="settings-manager.form.button.cancel">
                  {(message) => (
                    <Button onClick={this.handleToggle} className={styles.secondary}>{message}</Button>
                  )}
                </FormattedMessage>
                {loader}
              </ModalFooter>
            </form>
          </Modal>
        </div>
        <div>
          <PopUpWarning
            isOpen={this.state.warning}
            toggleModal={this.toggleWarning}
            onConfirm={this.props.data.isUsed ? this.toggleWarning : this.deleteDatabase}
            content={content}
            popUpWarningType={this.props.data.isUsed ? 'danger' : 'warning'}
            onlyConfirmButton={this.props.data.isUsed}
          />
        </div>
      </li>
    );
  }
}

RowDatabase.propTypes = {
  data: PropTypes.object,
  error: PropTypes.bool,
  formErrors: PropTypes.array,
  getDatabase: PropTypes.func,
  onDeleteDatabase: PropTypes.func,
  onSubmit: PropTypes.func,
};

export default RowDatabase;
