<?php

$plugin = array(
  'title' => t('World Data'),
  'format callback' => 'cc_awe_format_world_generate',
  'type' => 'world',
  'weight' => -80,
);

//Note that we do not make difference between "administrative area", "region", "state".

//Output region name instead of it's code.
function _cc_awe_pre_render($format) {
  $a = isset($format['#address']['administrative_area']) ? $format['#address']['administrative_area'] : NULL;
  $c = isset($format['#address']['administrative_area']) ? $format['#address']['administrative_area'] : NULL;
  if($a && $c) {
    $format['#address']['administrative_area'] = _cc_awe_region($a, $c);
  }
  return $format;
}

//$format - input form.
//$address - address itself.
//$context - additional data.
function cc_awe_format_world_generate(&$format, $address, $context = array()) {
  $c = isset($address['country']) ? $address['country'] : NULL;
  if($context['mode'] == 'render') {
    if($c == 'US' || $c == 'CA') {
      return FALSE;
    }
    $format['#pre_render'][] = '_cc_awe_pre_render';
    return FALSE;
  }
  if($c == 'US' || $c == 'CA') {
    $regs = array_filter(
      $format['locality_block']['administrative_area']['#options'],
      '_cc_awe_is_not_separator'
    );
  }else{
    $regs = _cc_awe_regions($c);
  }
  unset($format['locality_block']['administrative_area']);
  $format['locality_block']['administrative_area'] = array(
    '#title' => t('State'),
    '#type' => 'select',
    '#options' => $regs
  );
}
