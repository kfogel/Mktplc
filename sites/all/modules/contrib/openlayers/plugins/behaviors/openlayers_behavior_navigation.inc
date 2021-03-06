<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
$plugin = array(
  'title' => t('Navigation'),
  'description' => t('Provides the ability to navigate the map interface.'),
  'type' => 'map',
  'behavior' => array(
    'file' => 'openlayers_behavior_navigation.inc',
    'class' => 'openlayers_behavior_navigation',
    'parent' => 'openlayers_behavior',
  ),
);

/**
 * Navigation Behavior
 */
class openlayers_behavior_navigation extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'navigation' => '',
      'zoomWheelEnabled' => TRUE,
      'documentDrag' => FALSE,
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.Navigation');
  }

  function options_form($defaults) {
    return array(
      'zoomWheelEnabled' => array(
        '#type' => 'checkbox',
        '#title' => t('Enable Zoom Wheel'),
        '#description' => t('Enable zooming via the mouse scroll wheel. This can 
          interfere with page scrolling.'),
        '#default_value' => isset($defaults['zoomWheelEnabled']) ? $defaults['zoomWheelEnabled'] : TRUE 
      ),
      'documentDrag' => array(
        '#type' => 'checkbox',
        '#title' => t('Document Drag'),
        '#description' => t('Allow panning of the map by dragging outside map viewport.'),
        '#default_value' => isset($defaults['documentDrag']) ? $defaults['documentDrag'] : FALSE
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') . 
      '/plugins/behaviors/openlayers_behavior_navigation.js');
    return $this->options;
  }
}
