<?php

/**
 * @file
 * Provides user_track view fields and filters.
 */

 /**
  * Implements hook_views_data().
  */
function user_track_views_data() {
  $data['user_track']['table']['group'] = t('User track.');
  $data['user_track']['table']['base'] = array(
    'field' => 'uid',
    'title' => t('User track table.'),
    'help' => t('Maps to uid in user table.'),
    'weight' => -10,
  );
  $data['user_track']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
  // UID field.
  $data['user_track']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('Unique of user.'),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User uid'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  // Access Time field.
  $data['user_track']['access'] = array(
    'title' => t('Access Time.'),
    'help' => t('Time of login.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  // IP field.
  $data['user_track']['ip'] = array(
    'title' => t('IP Address.'),
    'help' => t('IP address of user.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  // Agent field.
  $data['user_track']['agent'] = array(
    'title' => t('Agent.'),
    'help' => t('User agent of the user.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  // Status field.
  $data['user_track']['success'] = array(
    'title' => t('Status.'),
    'help' => t('Status of login:Success/Failed.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  return $data;
}
