(function ($) {
  Drupal.behaviors.aiocalendar = {
    attach: function(context) {
      
      // Hide the description as soon as it loads
      $('.view-field.view-data-node-revisions-body.node-revisions-body', context).once('hidden', function(){
        $(this).hide();
      });

  };
   
})(jQuery);

