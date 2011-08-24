// Drupal.behaviors.aioCheckAll = function (context) {
//   // HTML for checkall checkbox.
//   checkall_html = '<div id="checkall" class="form-item">         \
//  <label><input type="checkbox"    \
//   class="form-checkbox""/> \
//   <span id="checkall-text">Check All</span></label>                                               \
// </div>                                                            \
//   ';
//   
//   // Add html for the check all checkbox. 
//   $("#views-exposed-form-events-calendar-calendar-1 .form-checkboxes")
//   .prepend(checkall_html);
//   
//   // If all checkboxes are checked, set the check all as checked as well.
//   var allchecked = true;
//   $("form#views-exposed-form-events-calendar-calendar-1 .option [type='checkbox']").each(function() {
//     if ($(this).attr('checked') == false) {
//       allchecked = false;
//     }
//   });
//   
//   // If all are checked, change text to uncheck all.
//   if (allchecked) {
//     $("#checkall-text").html("Uncheck All");
//     
//     // If Uncheck all is clicked, unselect all but do not submit form automatically as Views
//     // doesn't all you to submit a form w/ no checkboxes selected.
//     $("#checkall [type='checkbox']").bind(($.browser.msie ? "click" : "change"), function () {
//       var checked_value = $("#checkall [type='checkbox']").attr('checked');
//       $("form#views-exposed-form-events-calendar-calendar-1 .option [type='checkbox']").each(function() {
//         $(this).attr('checked', !checked_value);
//       });
//     });  
//   }
//   // Else, check all and resubmit.
//   else {
//     // Set change event for the checkall checkbox.
//     $("#checkall [type='checkbox']").bind(($.browser.msie ? "click" : "change"), function () {
//       $("form#views-exposed-form-events-calendar-calendar-1 .option [type='checkbox']").each(function() {
//         $(this).attr('checked', true);
//       });
//       
//       // Resubmit form.
//       $("form#views-exposed-form-events-calendar-calendar-1").submit();
//     });  
//   }
//   
// }

themeToolTips = function(data) {
  // Object should include title, time, location, image, and paragraph
  html = "";
  
  html += "<div class='tooltip-event'>";
  html += "<h2>" + data.title + "</h2>"; // Title
  html += "<strong>Time:</strong> " + data.time;
  html += "<br />";
  if (data.location.length > 0) {
    html += "<strong>Location:</strong> " + data.location;
    html += "<br />";  
  }

  if (data.paragraph != "<p></p>") {
    html += "<hr />";
    html += "<div class='event-summary-tooltip clear-block'>";
    html += $(data.paragraph).text();    
  }
  
  html += "</div></div>";
  
  return html;
}

// Add tooltips to show extra information about calendar events.
Drupal.behaviors.aio_beautytip = function (context) {
  
  getContent = function (dateBox) {
    var data = {};
    
    var pieces = $(dateBox).eq(0).children().slice(1);
    
    data.title = jQuery.trim($(pieces).find("a").parent().text());
      
    // If a normal event (w/ beginning and end dates).
    if ($(pieces).find(".date-display-start").length) {
      data.time = jQuery.trim($(pieces)
                                      .find(".date-display-start")
                                      .text());
      data.time += " to ";
      data.time += jQuery.trim($(pieces)
                            .find(".date-display-end")
                            .text());
      }
    // If all-day-event.
    else if ($(pieces).find(".date-display-single")
        .length > 0) {
      var time = jQuery.trim($(pieces)
                                    .find(".date-display-single")
                                    .text());
      // Clean off the month from the time.
      timeStr = "";
      timeArr = time.split(" - ");
      
      if (timeArr.length > 1) {
        timeStr = timeArr[1]; // Not all dates have a dash.
      }
      else {
        timeStr = time;
      }
      data.time = timeStr;
    }
    
    // If there's a location.
    // TODO simplify this. This is a big fat crappy piece of javascript.
    data.location = "";
    if ($(pieces)
        .find(".view-label-node-data-field-event-image-field-event-location-value").length > 0) {
      var event_location = jQuery.trim($(pieces) 
                  .find(".view-label-node-data-field-event-image-field-event-location-value")
                  .parent()
                  .text());
      event_location = event_location.split("Location");
      data.location = jQuery.trim(event_location[1]);
    }
    
    // If summary.
    // data.image = "";
    // // If image.
    // if ($(pieces).find("img").parent().length > 0) {
    //   image = jQuery.trim($(pieces).find("img").parent().html());
    //   image = $(image).addClass('event-tooltip-image').parent().html();
    //   data.image = image;
    // }
    
    // console.log(jQuery.trim($(pieces).find('p').parent().html()));
    
    if ($(pieces).find("p").length > 0) {
      paragraph = jQuery.trim($(pieces).find("p").parent().html());  
      data.paragraph = paragraph;
    }
    
    if (typeof data.paragraph == 'undefined') {
      data.paragraph = "<p></p>";
    }

    return themeToolTips(data);
  }
  
  // TODO Add hover intent and make people hover .25 secs or so. Plus unbind all the other links when one is clicked until
  // a tooltip is closed.
  closeResetToolTips = function () {
    $(".bt-active").unbind().btOff().bind("click", this, btOnClick);
    
    // Reset hover beauty tips.
    setBeautyTips();
    
    // Reset click events for all the calendars.
    setBeautyTipClickEvent();
  }

  setBeautyTips = function() {
    $(".inner .calendar:has('.stripe')").bt({
      contentSelector: "getContent(this)",
      positions: ['right', 'left'],
      fill: '#F4F4F4',
      strokeStyle: '#666666',
      spikeLength: 20,
      spikeGirth: 10,
      width: 300,
      overlap: 0,
      centerPointY: 1,
      cornerRadius: 0,
      cssStyles: {
        fontFamily: '"Lucida Grande",Helvetica,Arial,Verdana,sans-serif',
        fontSize: '12px',
        padding: '10px 14px'
      },
      shadow: true,
      shadowColor: 'rgba(0,0,0,.5)',
      shadowBlur: 8,
      shadowOffsetX: 4,
      shadowOffsetY: 4
    });
  }
  
  // btOnClick = function (dateBox) {
  //   closeResetToolTips();
  //   
  //   $(this).bt({
  //       contentSelector: "$('#hulu-content')",
  //       positions: ['right', 'left'],
  //       fill: '#F4F4F4',
  //       strokeStyle: '#666666', 
  //       spikeLength: 20,
  //       spikeGirth: 10,
  //       width: 350,
  //       overlap: 0,
  //       centerPointY: 1,
  //       cornerRadius: 0, 
  //       cssStyles: {
  //         fontFamily: '"Lucida Grande",Helvetica,Arial,Verdana,sans-serif', 
  //         fontSize: '12px',
  //         padding: '10px 14px'
  //       },
  //       shadow: true,
  //       shadowColor: 'rgba(0,0,0,.5)',
  //       shadowBlur: 8,
  //       shadowOffsetX: 4,
  //       shadowOffsetY: 4
  //       contentSelector: "getContentShare(this)",
  //       //         fill: 'rgba(222, 240, 252, .85)',
  //       //         cssStyles: {color: 'black', fontWeight: 'bold'},
  //       //         shrinkToFit: true,
  //       //         trigger: ['mouseover', 'click'],
  //       //         padding: 20,
  //       //         clickAnywhereToClose: false,
  //       //         cornerRadius: 20,
  //       //         spikeLength: 15,
  //       //         spikeGirth: 25,
  //       //         width: 500,
  //       //         positions: ['left', 'right', 'bottom', 'top']
  //     });
  //   $(this).btOn();
  //   $(this).unbind('mouseout');
  //   // Set click event on email event
  //   $(".email-event").click(addTextBoxForEmails);
  //   unbindAllExceptActive();
  //   
  //   return false;
  // }
  
  // addTextBoxForEmails = function() {
  //    // Change hidden values for the event Node ID and the active categories.
  //    $("#edit-nid-1").attr('value', Drupal.settings.aiocalendar.nid);
  //    $("#edit-ical-feed-url-1").attr('value', Drupal.settings.aiocalendar.ical_feed);
  //    $("#aiocalendar-email-event-form-1").dialog('open');
  //  }
  //  // Unbind all except active
  //  unbindAllExceptActive = function () {
  //    $(".inner .calendar:has('.stripe'):not('.bt-active')").unbind().bind("click", this, btOnClick);
  //  }
  //  
  //  setBeautyTipClickEvent = function() {
  //    $(".inner .calendar:has('.stripe')").bind("click", this, btOnClick);  
  //  }
  
  // Set beautytips.
  setBeautyTips();
  
  // Set click events for all the calendars.
  // setBeautyTipClickEvent();
  
  // Setup up jQuery UI dialog for the form.
}

// This function does two things. First it moves the ical icon from the bottom
// to the top of the page on each refresh of the calendar. Second, as the RSS
// feed icons don't change when category checkboxes are updated. This code
// keeps the rss icon url in sync w/ what event categories are being shown.
Drupal.behaviors.moveIcalIcon = function (context) {
  $("#content_top .ical-icon").remove();
  $("#content_top").prepend($(".ical-icon"));
  
  // Set the RSS icon's URL
  ical_feed = $(".ical-icon").attr('href');
  if(typeof(ical_feed) != "undefined") {
    match = /ical\/(.*)/.exec(ical_feed);
    ical_tids = match[1];
    rss_feed = $("a.feed-icon").attr('href');
    rss_feed = rss_feed.replace(/rss\/(.*)/g,"rss/"+ical_tids);
    $("a.feed-icon").attr('href', rss_feed);
  }
}

// Hide the long descriptions on the calendar
Drupal.behaviors.truncateLongDesc = function () {
  
}



if (Drupal.jsEnabled) {
  $(document).ready(function(){
    // Hide the description as soon as it loads
    $('.view-field.view-data-node-revisions-body.node-revisions-body').hide();
  });
}


