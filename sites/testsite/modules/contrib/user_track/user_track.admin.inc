<?php

/**
 * @file
 * Administration page callbacks for the user track module.
 */

/**
 * Form builder. Configure annotations.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function user_track_admin_settings() {
  $form['user_track']['user_track_ip_address'] = array(
    '#type' => 'checkbox',
    '#title' => t('Track IP addresses.'),
    '#description' => 'Check to track IP addresses. This can be a privacy issue!.',
    '#default_value' => variable_get('user_track_ip_address', TRUE),
  );
  $form['#submit'][] = 'user_track_admin_settings_submit';
  return system_settings_form($form);
}

/**
 * Submit function for user track admin settings.
 */
function user_track_admin_settings_submit($form, &$form_state) {
  $track_ips = $form_state['values']['user_track_ip_address'];
  variable_set('user_track_ip_address', $track_ips);
}
