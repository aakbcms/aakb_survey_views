<?php
/**
 * @file
 * aakb_survey_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function aakb_survey_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'survey_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Survey export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Survey export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'export aakb survey';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Aakb survey: Survey consent information */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'aakb_survey';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Display name */
  $handler->display->display_options['fields']['data']['id'] = 'data';
  $handler->display->display_options['fields']['data']['table'] = 'users';
  $handler->display->display_options['fields']['data']['field'] = 'data';
  $handler->display->display_options['fields']['data']['ui_name'] = 'Display name';
  $handler->display->display_options['fields']['data']['label'] = 'Name';
  $handler->display->display_options['fields']['data']['format'] = 'key';
  $handler->display->display_options['fields']['data']['key'] = 'display_name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Contextual filter: Aakb survey: Consent */
  $handler->display->display_options['arguments']['consent']['id'] = 'consent';
  $handler->display->display_options['arguments']['consent']['table'] = 'aakb_survey';
  $handler->display->display_options['arguments']['consent']['field'] = 'consent';
  $handler->display->display_options['arguments']['consent']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['consent']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['consent']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['consent']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['consent']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'aakb_survey_cvs_export');
  $handler->display->display_options['display_description'] = 'User consent export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full_aakb.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 0;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/config/people/survey/export/%/csv';

  /* Display: XLS */
  $handler = $view->new_display('views_data_export', 'XLS', 'aakb_survey_xls_export');
  $handler->display->display_options['display_description'] = 'User consent export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full_aakb.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/config/people/survey/export/%/xls';
  $translatables['survey_export'] = array(
    t('Master'),
    t('Survey export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Survey consent relationship'),
    t('Name'),
    t('All'),
    t('CSV'),
    t('User consent export'),
    t('XLS'),
  );
  $export['survey_export'] = $view;

  return $export;
}
