<?php
/**
 * @file
 * aiocalendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function aiocalendar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function aiocalendar_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function aiocalendar_node_info() {
  $items = array(
    'calendar_event' => array(
      'name' => t('Calendar Event'),
      'base' => 'node_content',
      'description' => t('Events to be shown in the All-in-One Calendar'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
