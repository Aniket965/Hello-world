/*
 *
 * LanguageProvider actions
 *
 */

import {
  FREEZE_APP,
  LOAD_PLUGIN,
  PLUGIN_DELETED,
  PLUGIN_LOADED,
  UNFREEZE_APP,
  UNSET_HAS_USERS_PLUGIN,
  UPDATE_PLUGIN,
} from './constants';

export function freezeApp() {
  return {
    type: FREEZE_APP,
  };
}

export function loadPlugin(newPlugin) {
  return {
    type: LOAD_PLUGIN,
    plugin: newPlugin,
  };
}

export function pluginDeleted(plugin) {
  return {
    type: PLUGIN_DELETED,
    plugin,
  };
}

export function pluginLoaded(newPlugin) {
  return {
    type: PLUGIN_LOADED,
    plugin: newPlugin,
  };
}

export function unfreezeApp() {
  return {
    type: UNFREEZE_APP,
  };
}

export function unsetHasUserPlugin() {
  return {
    type: UNSET_HAS_USERS_PLUGIN,
  };
}

export function updatePlugin(pluginId, updatedKey, updatedValue) {
  return {
    type: UPDATE_PLUGIN,
    pluginId,
    updatedKey,
    updatedValue,
  };
}
