<?php

/**
 * Implementation of hook_node_info().
 */
function aiocalendar_node_info() {
  $items = array(
    'calendar_event' => array(
      'name' => t('Calendar Event'),
      'module' => 'features',
      'description' => t('Events to be shown in the All-in-One Calendar'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function aiocalendar_views_api() {
  return array(
    'api' => '2',
  );
}
