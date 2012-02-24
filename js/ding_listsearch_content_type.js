(function ($) {
  // Delete row functionality.
  $('#listsearch-items-table tr a.delete-row-link').live('click', function(e){
    e.preventDefault();
    var tr = $(this).parents('tr:first');
    // Empty fields.
    var textFields = tr.find('input[type=text]');
    textFields.each(function(){
      $(this).val('');
    });
    // Hide row.
    tr.hide();
    // Change even/odd classes.
    tr.nextAll('tr').each(function(){
      var thisTr = $(this);
      if (thisTr.hasClass('odd')) {
        thisTr.removeClass('odd').addClass('even');
      }
      else if (thisTr.hasClass('even')) {
        thisTr.removeClass('even').addClass('odd');
      }
    });
  });
})(jQuery);
