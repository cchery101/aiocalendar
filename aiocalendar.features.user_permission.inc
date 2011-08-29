<?php

/**
 * @file
 * User permissions items.
 */


/**
 * Implementation of hook_user_default_permissions().
 */
function aiocalendar_user_default_permissions() {
  $permissions = array();

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
  );

  // Exported permission: create calendar_event content
  $permissions['create calendar_event content'] = array(
    'name' => 'create calendar_event content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any calendar_event content
  $permissions['delete any calendar_event content'] = array(
    'name' => 'delete any calendar_event content',
    'roles' => array(),
  );

  // Exported permission: delete own calendar_event content
  $permissions['delete own calendar_event content'] = array(
    'name' => 'delete own calendar_event content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit any calendar_event content
  $permissions['edit any calendar_event content'] = array(
    'name' => 'edit any calendar_event content',
    'roles' => array(),
  );

  // Exported permission: edit field_event_date
  $permissions['edit field_event_date'] = array(
    'name' => 'edit field_event_date',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_event_location
  $permissions['edit field_event_location'] = array(
    'name' => 'edit field_event_location',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_image
  $permissions['edit field_image'] = array(
    'name' => 'edit field_image',
    'roles' => array(),
  );

  // Exported permission: edit own calendar_event content
  $permissions['edit own calendar_event content'] = array(
    'name' => 'edit own calendar_event content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: view field_event_date
  $permissions['view field_event_date'] = array(
    'name' => 'view field_event_date',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_event_location
  $permissions['view field_event_location'] = array(
    'name' => 'view field_event_location',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_image
  $permissions['view field_image'] = array(
    'name' => 'view field_image',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
