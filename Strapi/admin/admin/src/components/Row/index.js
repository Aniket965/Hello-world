/*
*
* Row
*
*/

import React from 'react';
import PropTypes from 'prop-types';
import cn from 'classnames';
import { FormattedMessage } from 'react-intl';
import { isEmpty } from 'lodash';

// Design
import IcoContainer from 'components/IcoContainer';
import ListRow from 'components/ListRow';
import PopUpWarning from 'components/PopUpWarning';

import styles from './styles.scss';

class Row extends React.Component {
  state = { showModal: false };

  componentWillReceiveProps(nextProps) {
    if (nextProps.pluginActionSucceeded !== this.props.pluginActionSucceeded) {
      this.setState({ showModal: false });
    }
  }

  handleClick = (e) => {
    this.setState({ showModal: !this.state.showModal });
    this.props.onDeleteClick(e);
  }

  render() {
    const uploadPath = `/plugins/upload/configurations/${this.context.currentEnvironment}`;
    const icons = this.props.name === 'upload' ? [
      {
        icoType: 'cog',
        onClick: (e) => {
          e.preventDefault();
          e.stopPropagation();
          this.context.router.history.push(uploadPath);
        },
      },
      {
        icoType: 'trash',
        id: this.props.name,
        onClick: this.handleClick,
      },
    ] : [
      {
        icoType: 'trash',
        id: this.props.name,
        onClick: this.handleClick,
      },
    ];

    return (
      <ListRow>
        <div className={cn("col-md-11", styles.nameWrapper)}>
          <div className={styles.icoContainer} style={{ marginRight: '14px' }}>
            {!isEmpty(this.props.plugin.logo) && <img src={`${this.props.plugin.logo}`} alt="icon" />}
            { isEmpty(this.props.plugin.logo) && (
              <div className={styles.icoWrapper}>
                <i className={`fa fa-${this.props.plugin.icon}`} />
              </div>
            )}
          </div>
          <div className={styles.pluginContent}>
            <span>{this.props.plugin.name} —&nbsp;</span>
            <FormattedMessage id={`${this.props.plugin.description}.short`} defaultMessage={this.props.plugin.description} />
          </div>
        </div>
        <div className="col-md-1">
          <div className={styles.actionContainer}>
            <IcoContainer icons={icons} />
          </div>
        </div>
        <PopUpWarning
          isOpen={this.state.showModal}
          toggleModal={() => this.setState({ showModal: !this.state.showModal })}
          popUpWarningType="danger"
          onConfirm={this.props.onDeleteConfirm}
        />
      </ListRow>
    );
  }
}

Row.contextTypes = {
  currentEnvironment: PropTypes.string,
  router: PropTypes.object,
};

Row.propTypes = {
  name: PropTypes.string.isRequired,
  onDeleteClick: PropTypes.func.isRequired,
  onDeleteConfirm: PropTypes.func.isRequired,
  plugin: PropTypes.object.isRequired,
  pluginActionSucceeded: PropTypes.bool.isRequired,
};

export default Row;
