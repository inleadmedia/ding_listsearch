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
  // Sort by weight.
  $conf['searches'] = ding_listsearch_list_search_content_type_sort($conf['searches']);
  $block          = new stdClass();
  $block->title   = t('Search recommendations');
  $block->content = theme('ding_list_search_items', array('items' => $conf['searches']));
  return $block;
}

function ding_listsearch_list_search_content_type_sort($items) {
  $sorted_items;
  foreach ($items as $i => $item) {
    $weight = $item['weight'];
    while(isset($sorted_items[$weight])) {
      $weight++;
    }
    $sorted_items[$weight] = $item;
  }
  unset($items);
  ksort($sorted_items);
  return $sorted_items;
}
