<?php
/**
 * @file
 * Provide default views.
 */

/**
 * Implements hook_views_default_views().
 */
function user_track_views_default_views() {

  $track_ips = variable_get('user_track_ip_address');
  $view = new view();
  $view->name = 'user_track';
  $view->description = 'View user tracking details of users.';
  $view->tag = '';
  $view->base_table = 'user_track';
  $view->human_name = 'User Track';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handle->display->display_options['title'] = 'User Track.';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'access' => 'access',
    'ip' => 'ip',
    'agent' => 'agent',
    'success' => 'success',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'access' => array(
      'sortable' => 1,
      'sepatator' => '',
    ),
    'ip' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'agent' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'success' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;

  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'No results found.';
  $handler->display->display_options['empty']['text']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['text']['tokenize'] = 0;
  /* Relationship: User Track: User id */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'user_track';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = '0';

  /* Field: Login Timestamp */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'user_track';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['access']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['access']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['access']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['access']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['access']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['access']['alter']['html'] = 0;
  $handler->display->display_options['fields']['access']['hide_empty'] = 0;
  $handler->display->display_options['fields']['access']['empty_zero'] = 0;
  /* Field: IP Address */
  $handler->display->display_options['fields']['ip']['id'] = 'ip';
  $handler->display->display_options['fields']['ip']['table'] = 'user_track';
  $handler->display->display_options['fields']['ip']['field'] = 'ip';
  $handler->display->display_options['fields']['ip']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ip']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ip']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ip']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ip']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ip']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ip']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ip']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ip']['empty_zero'] = 0;

  // Exclude the IP Address from display, if unchecked from the configuration.
  if (!$track_ips) {
    $handler->display->display_options['fields']['ip']['exclude'] = TRUE;
  }
  /* Field: Agent */
  $handler->display->display_options['fields']['agent']['id'] = 'agent';
  $handler->display->display_options['fields']['agent']['table'] = 'user_track';
  $handler->display->display_options['fields']['agent']['field'] = 'agent';
  $handler->display->display_options['fields']['agent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['agent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['agent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['agent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['agent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['agent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['agent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['agent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['agent']['empty_zero'] = 0;
  /* Field: Status */
  $handler->display->display_options['fields']['success']['id'] = 'success';
  $handler->display->display_options['fields']['success']['table'] = 'user_track';
  $handler->display->display_options['fields']['success']['field'] = 'success';
  $handler->display->display_options['fields']['success']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['success']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['success']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['success']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['success']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['success']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['success']['alter']['html'] = 0;
  $handler->display->display_options['fields']['success']['hide_empty'] = 0;
  $handler->display->display_options['fields']['success']['empty_zero'] = 0;

  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Sort criterion: User IP: Login Timestamp */
  $handler->display->display_options['sorts']['access']['id'] = 'access';
  $handler->display->display_options['sorts']['access']['table'] = 'user_track';
  $handler->display->display_options['sorts']['access']['field'] = 'access';
  $handler->display->display_options['sorts']['access']['order'] = 'DESC';

  /* Filter criterion: User track.: IP Address. */
  if ($track_ips) {
    $handler->display->display_options['filters']['ip']['id'] = 'ip';
    $handler->display->display_options['filters']['ip']['table'] = 'user_track';
    $handler->display->display_options['filters']['ip']['field'] = 'ip';
    $handler->display->display_options['filters']['ip']['operator'] = 'starts';
    $handler->display->display_options['filters']['ip']['exposed'] = TRUE;
    $handler->display->display_options['filters']['ip']['expose']['operator_id'] = 'ip_op';
    $handler->display->display_options['filters']['ip']['expose']['label'] = 'IP Address';
    $handler->display->display_options['filters']['ip']['expose']['operator'] = 'ip_op';
    $handler->display->display_options['filters']['ip']['expose']['identifier'] = 'ip';
    $handler->display->display_options['filters']['ip']['expose']['required'] = 0;
    $handler->display->display_options['filters']['ip']['expose']['multiple'] = FALSE;
  }

  /* Filter criterion: User track.: Status. */
  $handler->display->display_options['filters']['success']['id'] = 'success';
  $handler->display->display_options['filters']['success']['table'] = 'user_track';
  $handler->display->display_options['filters']['success']['field'] = 'success';
  $handler->display->display_options['filters']['success']['value'] = '';
  $handler->display->display_options['filters']['success']['exposed'] = TRUE;
  $handler->display->display_options['filters']['success']['expose']['operator_id'] = 'success_op';
  $handler->display->display_options['filters']['success']['expose']['label'] = 'Login status';
  $handler->display->display_options['filters']['success']['expose']['operator'] = 'success_op';
  $handler->display->display_options['filters']['success']['expose']['identifier'] = 'success';
  $handler->display->display_options['filters']['success']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['success']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%user/user-track';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'User Track';
  $handler->display->display_options['menu']['description'] = 'View tracking parameters of the users.';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  $views[$view->name] = $view;
  return $views;
}
