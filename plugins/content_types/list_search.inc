<?php
/**
 * @file
 * List search pane for ctools.
 */

$plugin = array(
  'title' => t('Ding list search'),
  'description' => t('List of recommended search results.'),
  'single' => TRUE,
  'category' => t('Ding!'),
);

/**
 * Implements MODULE_CONTENT_content_type_render().
 *
 * Render the block.
 */
function ding_listsearch_list_search_content_type_render($subtype, $conf, $panel_args, $context) {
  $block          = new stdClass();
  $block->title   = t('Search recommendations');
  $block->content = '
    <ul>
      <li><a href="/search/ting/dc.creator=Dorthe">Dorthe nors</a></li>
      <li><a href="/search/ting/dc.creator=Tolkien">Tolkien</a></li>
    </ul>
  ';
  return $block;
}

/**
 * Returns an edit form for the content type.
 */
function ding_listsearch_list_search_content_type_edit_form($form, &$form_state) {
  $form['searches'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );
  $form['searches'][] = _ding_listsearch_list_search_item_form($form, $form_state);
  return $form;
}

function _ding_listsearch_list_search_item_form($form, &$form_state) {
  $form = array(
    '#type' => 'fieldset',
  );
  $form['title'] = array(
    '#type' => 'textfield',
    '#title'=> t('Title'),
    '#default_value' => '',
  );
  $form['search_params'] = array(
    '#type' => 'textfield',
    '#title'=> t('Search phrase'),
    '#default_value' => '',
  );
  $form['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#title_display' => 'invisible',
    '#default_value' => 1,
    '#delta' => 50,
  );
  return $form;
}
