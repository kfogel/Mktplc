<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
**/ 

// Add some cool text to the search block form
function civiccommons_form_alter(&$form, &$form_state, $form_id) {

  if ($form_id == 'search_block_form') {
    // HTML5 placeholder attribute
    $form['search_block_form']['#attributes']['placeholder'] = t('Enter Keyword');
    $form['actions']['submit']['#value'] = t(''); // Change the text on the submit button
    $form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/search_btn.png');

}
}

/**
 * Preprocessor for page.tpl.php template file.
 */
function civiccommons_preprocess_page(&$vars, $hook) {
  //drupal_add_js('https://getsatisfaction.com/civiccommons/widgets/javascripts/7f68acfc31/widgets.js', 'external',  array('weight' => 100));
  //drupal_add_js('https://getsatisfaction.com/civiccommons/topics.widget?callback=gsfnTopicsCallback&amp;style=idea', 'external', array('weight' => 100));
  drupal_add_js(drupal_get_path('theme', 'civiccommons') .'/js/getsatisfaction1.js', 'file');
  drupal_add_js(drupal_get_path('theme', 'civiccommons') .'/js/getsatisfaction2.js', 'file');
  drupal_add_js(drupal_get_path('theme', 'civiccommons') .'/js/googleanalytics.js', 'file');
}


/* Search */
function civiccommons_preprocess_search_result (&$vars) {
  $vars['nodetype'] = $vars['result']['type'];
}





function civiccommons_preprocess_region(&$vars) {
  if (isset($vars['elements']['#page']['node']) && $vars['elements']['#region'] == 'content') {
    $vars['theme_hook_suggestions'][] = 'region__content__'. $vars['elements']['#page']['node']->type;
  }

}

function civiccommons_menu_local_tasks(&$variables) {
/*  if($GLOBALS['user']->uid != 1) {
    return '';
  }*/
  $output = '';
  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}
?>
