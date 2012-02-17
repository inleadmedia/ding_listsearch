<?php

/**
 * @file
 * Default theme implementation to format the ding list search.
 *
 * Copy this file in your theme directory to create a custom themed body.
 *
 * Available variables:
 * - $items: Array of searches with params
 */
?>
<div class="list-search-items">
  <?php foreach ($items as &$item) { ?>
  <div class="item">
    <a href="<?php echo url('search/ting') . '/' . $item['search_params']; ?>"><?php echo $item['title'] ?></a>
  </div>
  <?php } ?>
</div>
