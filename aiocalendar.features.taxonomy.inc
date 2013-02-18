<?php
/**
 * @file
 * aiocalendar.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function aiocalendar_taxonomy_default_vocabularies() {
  return array(
    'event_type' => array(
      'name' => 'Event Type',
      'machine_name' => 'event_type',
      'description' => 'Event Categories for the AIO Calendar',
      'hierarchy' => '0',
      'module' => 'aiocalendar',
      'weight' => '0',
    ),
    'events' => array(
      'name' => 'Events',
      'machine_name' => 'events',
      'description' => 'Select the type of event.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
