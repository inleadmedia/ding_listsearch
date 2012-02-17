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
