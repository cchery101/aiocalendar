<?php

/**
 * Implementation of hook_content_default_fields().
 */
// function aiocalendar_content_default_fields() {
//   $fields = array();
// 
//   // Exported field: field_event_date
//   $fields['calendar_event-field_event_date'] = array(
//     'field_name' => 'field_event_date',
//     'type_name' => 'calendar_event',
//     'display_settings' => array(
//       'weight' => '-4',
//       'parent' => '',
//       'label' => array(
//         'format' => 'hidden',
//       ),
//       'teaser' => array(
//         'format' => 'long',
//         'exclude' => 0,
//       ),
//       'full' => array(
//         'format' => 'long',
//         'exclude' => 0,
//       ),
//       '4' => array(
//         'format' => 'default',
//         'exclude' => 0,
//       ),
//       'token' => array(
//         'format' => 'default',
//         'exclude' => 0,
//       ),
//     ),
//     'widget_active' => '1',
//     'type' => 'date',
//     'required' => '1',
//     'multiple' => '0',
//     'module' => 'date',
//     'active' => '1',
//     'granularity' => array(
//       'year' => 'year',
//       'month' => 'month',
//       'day' => 'day',
//       'hour' => 'hour',
//       'minute' => 'minute',
//     ),
//     'timezone_db' => 'UTC',
//     'tz_handling' => 'site',
//     'todate' => 'optional',
//     'repeat' => 0,
//     'repeat_collapsed' => '0',
//     'default_format' => 'medium',
//     'widget' => array(
//       'default_value' => 'strtotime',
//       'default_value_code' => '+1 day',
//       'default_value2' => 'blank',
//       'default_value_code2' => '',
//       'input_format' => 'm/d/Y - H:i',
//       'input_format_custom' => '',
//       'increment' => '15',
//       'text_parts' => array(),
//       'year_range' => '-3:+10',
//       'label_position' => 'above',
//       'label' => 'Date',
//       'weight' => '-4',
//       'description' => '',
//       'type' => 'date_popup',
//       'module' => 'date',
//     ),
//   );
// 
//   // Exported field: field_event_location
//   $fields['calendar_event-field_event_location'] = array(
//     'field_name' => 'field_event_location',
//     'type_name' => 'calendar_event',
//     'display_settings' => array(
//       'weight' => '-2',
//       'parent' => '',
//       'label' => array(
//         'format' => 'inline',
//       ),
//       'teaser' => array(
//         'format' => 'default',
//         'exclude' => 0,
//       ),
//       'full' => array(
//         'format' => 'default',
//         'exclude' => 0,
//       ),
//       '4' => array(
//         'format' => 'default',
//         'exclude' => 0,
//       ),
//       'token' => array(
//         'format' => 'default',
//         'exclude' => 0,
//       ),
//     ),
//     'widget_active' => '1',
//     'type' => 'text',
//     'required' => '0',
//     'multiple' => '0',
//     'module' => 'text',
//     'active' => '1',
//     'text_processing' => '0',
//     'max_length' => '',
//     'allowed_values' => '',
//     'allowed_values_php' => '',
//     'widget' => array(
//       'rows' => 5,
//       'size' => '60',
//       'default_value' => array(
//         '0' => array(
//           'value' => '',
//           '_error_element' => 'default_value_widget][field_event_location][0][value',
//         ),
//       ),
//       'default_value_php' => NULL,
//       'label' => 'Location',
//       'weight' => '-2',
//       'description' => '',
//       'type' => 'text_textfield',
//       'module' => 'text',
//     ),
//   );
// 
//   // Exported field: field_image
//   $fields['calendar_event-field_image'] = array(
//     'field_name' => 'field_image',
//     'type_name' => 'calendar_event',
//     'display_settings' => array(
//       'weight' => 0,
//       'parent' => '',
//       'label' => array(
//         'format' => 'hidden',
//       ),
//       'teaser' => array(
//         'format' => 'image_nodelink',
//         'exclude' => 0,
//       ),
//       'full' => array(
//         'format' => 'image_plain',
//         'exclude' => 0,
//       ),
//       '4' => array(
//         'format' => 'default',
//         'exclude' => 0,
//       ),
//     ),
//     'widget_active' => '1',
//     'type' => 'filefield',
//     'required' => '0',
//     'multiple' => '0',
//     'module' => 'filefield',
//     'active' => '1',
//     'list_field' => '0',
//     'list_default' => 1,
//     'description_field' => '0',
//     'widget' => array(
//       'file_extensions' => 'jpg gif png jpeg',
//       'file_path' => 'events',
//       'progress_indicator' => 'bar',
//       'max_filesize_per_file' => '',
//       'max_filesize_per_node' => '',
//       'filefield_sources' => array(
//         'imce' => 'imce',
//         'remote' => 'remote',
//         'reference' => 'reference',
//         'attach' => 'attach',
//       ),
//       'filefield_source_attach_path' => 'file_attach',
//       'filefield_source_attach_absolute' => '0',
//       'filefield_source_attach_mode' => 'move',
//       'filefield_source_autocomplete' => '0',
//       'max_resolution' => '0',
//       'min_resolution' => '0',
//       'alt' => '',
//       'custom_alt' => 1,
//       'title' => '',
//       'custom_title' => 0,
//       'title_type' => 'textfield',
//       'use_default_image' => 0,
//       'label' => 'Image',
//       'weight' => 0,
//       'description' => '',
//       'type' => 'imagefield_widget',
//       'module' => 'imagefield',
//     ),
//   );
// 
//   // Translatables
//   // Included for use with string extractors like potx.
//   t('Date');
//   t('Image');
//   t('Location');
// 
//   return $fields;
// }
