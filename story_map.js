/**
 * @file
 * A JavaScript file for the theme.
 */

(function ($, Drupal) {
  PRINT_DEBUG = false;

  /******************************************************************
    Leafleft Map
  ******************************************************************/
  Drupal.behaviors.leafletMap = {
    attach:function (context, settings) {

      /***********************************
        Map Creation
      ************************************/
      $(document).on("leaflet.map", function(event, map_settings, map) {
        /***********************************
          Map Layer Control
        ************************************/
        if(!map.layer_control) {
          //Create an empty overlay and set it as the active layer
          no_overlay = L.tileLayer('').addTo(map);

          // Create the Historical Image Overlay
          var historical_overlay_url = Drupal.settings.story_map.historical_map_overlay_path;
          var historical_overlay_bounds = [[ 49.301872803676254, -123.2984232902527], [49.20980365285424, -123.08159351348878]];
          historical_overlay = L.imageOverlay(historical_overlay_url, historical_overlay_bounds);

          // Add the overlays to a map layer control for toggling
          var overlays = {  "": historical_overlay }
          var overlay_options = { collapsed: false }
          map.layer_control = L.control.layers(null, overlays, overlay_options);

          /****** START - UNCOMMENT FOR MAP LAYER CONTROL ******

          map.layer_control.addTo(map);

          // Customize map layer control
          $('.leaflet-control-layers-overlays').find('input').hide();
          map_overlay_control_html = '<img class="map-overlay-control" src="' + Drupal.settings.story_map.map_overlay_control_path +'">';
          $('.leaflet-control-layers-overlays').find('span').append(map_overlay_control_html);

          ****** END - UNCOMMENT FOR MAP LAYER CONTROL ******/

          //Add iCheck wrapper to input
          $('.views-exposed-form input.form-control').iCheck({
            checkboxClass: 'icheckbox_square-grey',
            radioClass: 'iradio_square-grey',
            increaseArea: '20%' // optional
          });

          //Keep track of which neighbourhood layers have been added
          neighbourhood_layer_list = [];
        }

        /***********************************
          Remove the 'filter-processing'
          class on load
        ************************************/
        if($('.icheckbox_square-grey').hasClass('filter-processing')) {
          $('.icheckbox_square-grey').removeClass('filter-processing');
        }

        /***********************************
          Use styles to prevent filter spam.
          Auto-submit form when input state
          is changed
        ************************************/
        $('.views-exposed-form input.form-control').on('ifChanged', function(event){
          $('.icheckbox_square-grey').addClass('filter-processing');
          $(this).closest('form').find('.ctools-auto-submit-click').click();
        });

        /***********************************
          Display the currently selected
          Neighourhoods (KML file)
        ************************************/
        $('.views-exposed-form .views-widget-filter-neighbourhood input.form-control').each(function(i, obj) {
          filter_value = $(this).attr('value').toLowerCase().split(' ').join('_');
          if($(this).prop("checked") && !(neighbourhood_layer_list.indexOf(filter_value) > -1)) {
            neighbourhood_layer_list.push(filter_value);
            var kml_layer = new L.KML(Drupal.settings.story_map.neighbourhoods + '/' + filter_value + '.kml', {async: true});
            kml_layer.addTo(map);
          }
        });

        /***********************************
          URL Parameter Regex
        ************************************/
        pid_regex = /(\??|\&?)pid=(islandora:\d*)/;
        zoom_regex = /(\??|\&?)z=(\d*)/;
        cluster_regex = /(\??|\&?)c=true/;
        lat_regex = /(\??|\&?)lat=(-?\d*\.{0,1}\d*)*/;
        lng_regex = /(\??|\&?)lng=(-?\d*\.{0,1}\d*)*/;

        /***********************************
          Get Parameters from URL
        ************************************/
        if(document.location.search) {
          if(PRINT_DEBUG) { console.log('Get Parameters from URL: ' + document.location.href); }

          //PID
          pid = document.location.search.match(pid_regex);

          if(pid) {
            if(PRINT_DEBUG) { console.log('  PID: ' + pid[2]); }

            //Latitude and Longitude
            lat_coord = document.location.search.match(lat_regex);
            lng_coord = document.location.search.match(lng_regex);
            if(lat_coord && lng_coord) {
              map.panTo(L.latLng(parseFloat(lat_coord[2]), parseFloat(lng_coord[2])));
              if(PRINT_DEBUG) { console.log('  Latitude: ' + lat_coord[2]); }
              if(PRINT_DEBUG) { console.log('  Longitude: ' + lng_coord[2]); }
            }

            clustered = document.location.search.match(cluster_regex);
            if(PRINT_DEBUG) { console.log('  Clustered: ' + clustered); }
            if(clustered) {
              setTimeout(function() {
                map.setZoom(map.getMaxZoom());
              }, 1000);
            }

            //Zoom Level
            zoom_level = document.location.search.match(zoom_regex);
            if(zoom_level && !clustered) {
              if(PRINT_DEBUG) { console.log('  Zoom Level: ' + zoom_level[2]); }
              setTimeout(function() {
                 map.setZoom(zoom_level[2]);
              }, 1000);
            }

            setTimeout(function() {
              $('.leaflet-marker-pane .leaflet-tagged-marker').each(function(i, obj) {
                if(pid) {
                  if($(obj).find('div').length && $(obj).find('div')[0].innerHTML.match(/islandora:(\d*)/)[0] == pid[2]) {
                    $(obj).find('img').click();
                  }
                }
              });
            }, 2000);
          } else {
            map.setMaxZoom(17);
          }
        } else {
          map.setMaxZoom(17);
        }

        /***********************************
          Sort the list of checkboxes by
          value length

          Adjust URL Parameters when filtering
        ************************************/
        function sortByValueLength(a, b){
          var a_value_length = $(a).attr('value').length;
          var b_value_length = $(b).attr('value').length;
          return ((a_value_length > b_value_length) ? -1 : ((a_value_length < b_value_length) ? 1 : 0));
        }

        var filter_checkbox_list = $(document).find('.bef-checkboxes input.form-control');
        filter_checkbox_list.sort(sortByValueLength);

        filter_checkbox_list.each(function(i, obj) {
          filter_name = $(this).closest('.accordion').attr('class').split(' ').pop().split('-').pop();
          filter_regex = new RegExp('(\\??|\\&?)' + filter_name + '\\[\\]=' + $(this).attr('value'));

          if(document.location.href.match(filter_regex)) {
            if(!$(this).prop("checked")) {
                if(PRINT_DEBUG) { console.log('Removing Filter from URL: ' + filter_name); }
                //Loading in with filter and popup
                var new_url = document.location.href.replace(filter_regex, "");
                clearQueryData(map, new_url);

                if(PRINT_DEBUG) { console.log('  ' + document.location.href); }
            } else {
              return false;
            }
          }
        });

        /***********************************
          Adjust URL Parameters
          when popup closes
        ************************************/
        $(document).find('.leaflet-popup-pane').each(function(i, obj) {
          if(!$(obj).children() && document.location.href.match(pid_regex)) {
            clearQueryData(map);
          }
        });

        /***********************************
          Popup Open
        ************************************/
        map.on('popupopen', function(e) {
          if(PRINT_DEBUG) { console.log('Popup Open'); }
          // Add the media specific class to the wrapper for styling
          media_type = $(e.popup._wrapper).find('.story-media').attr('data-media-type');
          $(e.popup._wrapper).addClass('story-media-' + media_type);

          /***********************************
            Lightbox functionality
          ************************************/
          $(e.popup._wrapper).find('.story-media img').on('click', function(e) {
            e.preventDefault();
            var story_media = new story_media_lightbox($(this));
            story_media.init();
          });

          /***********************************
            Download functionality
          ************************************/
          if($(e.popup._wrapper).find('.story-media-download').length) {
            if($(e.popup._wrapper).find('.story-media[data-media-type="audio"]').length) {
              download_href = $(e.popup._wrapper).find('.story-media-download').attr('href').replace('OBJ', 'PROXY_MP3');
            } else if($(e.popup._wrapper).find('.story-media[data-media-type="video"]').length) {
              download_href = $(e.popup._wrapper).find('.story-media-download').attr('href').replace('OBJ', 'MP4');
            }

            $(e.popup._wrapper).find('.story-media-download').attr('href', download_href);
            $(e.popup._wrapper).find('.story-media-download').siblings('br:last').remove();
          }

          /***********************************
            Add URL parameters
          ************************************/
          if(!document.location.href.match(pid_regex)) {
            if($(e.popup._source._icon).find('div').length && document.location.href.match(/\?/)) {
              history.pushState(null, null, document.location.href + "&pid=" + $(e.popup._source._icon).find('div')[0].innerHTML);
            } else {
              history.pushState(null, null, document.location.href + "?pid=" + $(e.popup._source._icon).find('div')[0].innerHTML);
            }
            history.pushState(null, null, document.location.href + "&z=" + map.getZoom());
            history.pushState(null, null, document.location.href + "&lat=" + e.popup._source._latlng['lat']);
            history.pushState(null, null, document.location.href + "&lng=" + e.popup._source._latlng['lng']);

            if(e.popup._source._spiderLeg) {
              history.pushState(null, null, document.location.href + "&c=true");
            }

            if(PRINT_DEBUG) { console.log('  ' + document.location.href); }
          }
        });

        /***********************************
          Popup Close
        ************************************/
        map.on('popupclose', function(e) {
          if(PRINT_DEBUG) { console.log('Popup Close'); }
          /***********************************
            Remove URL parameters
          ************************************/
          clearQueryData(map);

          if(PRINT_DEBUG) { console.log('  ' + document.location.href); }
        });


        /***********************************
          Breakpoints
        ************************************/
        ssm.addState({
          id: 'narrow-screen-max',
          query: '(max-width: 767px)',
          onEnter: function() {
            if(PRINT_DEBUG) { console.log('Enter -- Narrow Screen Max'); }
            /***********************************
              Resets the map size after load
            ************************************/
            setTimeout(function() {
              map.invalidateSize();
            });

            /***********************************
              Auto-submit form when input state
              is changed

              Close mobile navigation menu
            ************************************/
            $('.views-exposed-form input.form-control').on('ifChanged', function(event){
              $('button.navbar-toggle').click();
              $(this).closest('form').find('.ctools-auto-submit-click').click();
            });

            /***********************************
              Add Sidebar and Footer Sponsers
              to Mobile Navigation
            ************************************/
            // Filters
            if($('nav.navbar-nav .view-filters').length == 0) {
              if($('nav.navbar-nav li').length) {
                $('nav.navbar-nav li:last').after($('.view-story-city .view-filters').detach());
              } else {
                $('nav.navbar-nav').append($('.view-story-city .view-filters').detach());
              }
            }

            if($('nav.navbar-nav .addtoany-wrapper').length == 0) {
              // AddtoAny Wrapper
              $('nav.navbar-nav .view-filters').after($('.view-story-city .addtoany-wrapper').detach());
            }

            // This Vancouver Wrapper
            $('nav.navbar-nav .addtoany-wrapper').after($('.view-story-city .this-vancouver-wrapper').detach());

            // Footer Sponsers
            $('footer .funding-credit').parent('.col-xs-9').after('<div class="sponsor-placeholder"></div>');
            $('nav.navbar-nav .this-vancouver-wrapper').after($('footer .funding-credit').parent('.col-xs-9').detach());
            $('.funding-credit').parent('.col-xs-9').removeClass().addClass('sponsor-wrapper');
          },
          onLeave: function() {
            if(PRINT_DEBUG) { console.log('Leave -- Narrow Screen Max'); }
            /***********************************
              Put back Sidebar and Footer Sponsors
            ************************************/
            // Footer Sponsors
            $('footer .sponsor-placeholder').after($('.funding-credit').parent('.sponsor-wrapper').detach());
            $('.funding-credit').parent('.sponsor-wrapper').removeClass().addClass('col-xs-9');
            $('footer .sponsor-placeholder').remove();

            // This Vancouver Wrapper
            $('.view-story-city .filter-share-wrapper').append($('nav.navbar-nav .this-vancouver-wrapper').detach());

            // AddtoAny Wrapper
            if($('.view-story-city .addtoany-wrapper').length) {
              $('nav.navbar-nav .addtoany-wrapper').remove();
            } else {
              $('.view-story-city .this-vancouver-wrapper').before($('nav.navbar-nav .addtoany-wrapper').detach());
            }

            // Filters
            if($('.view-story-city .view-filters').length) {
              $('nav.navbar-nav .view-filters').remove();
            } else {
              $('.view-story-city .addtoany-wrapper').before($('nav.navbar-nav .view-filters').detach());
            }
          }
        });
      });

      /***********************************
        Filter Accordions
      ************************************/
      $('.view-story-city .views-exposed-widgets .views-exposed-widget').each(function(i, obj) {
        if(!$(obj).hasClass('views-submit-button') && !$(obj).hasClass('views-reset-button')) {
          filter_accordion_html = '<div class="accordion ' + $(obj).attr('class').match(/views-widget-filter.*/) + '"">';
          filter_accordion_html += '<details><summary><strong>' + $(obj).find('label').html() + '</strong></summary>';
          filter_accordion_html += '<div class="accordion-content">' + $(obj).find('.views-widget')[0].outerHTML + '</div></details></div>';

          $(obj).after(filter_accordion_html);
          $(obj).remove();
        }

        // Delay displaying the Reset Button
        if($(obj).hasClass('views-reset-button')) {
          $(obj).show();
        }
      });

      /***********************************
        Wrapper for the sidebar elements
      ************************************/
      if($('.filter-share-wrapper').length == 0) {
        $('.view-story-city .view-content').before('<div class="filter-share-wrapper"></div>');
        $('.view-story-city .filter-share-wrapper').append($('.view-story-city .view-filters').detach());
      }

      /***********************************
        Keep Accordion open if it contains
        an active filter
      ************************************/
      $('.view-story-city .accordion-content .bef-checkboxes input').each(function(i, obj) {
        if($(obj).prop('checked')) {
          $(obj).closest('details').attr('open', true);
        }
      });

      /***********************************
        Format Filter icons for options
      ************************************/
      $('.view-story-city .views-widget-filter-format .form-type-bef-checkbox label').each(function(i, obj) {
        media_type = $(obj).attr('for').split('-').pop();

        if(media_type == "imag") {
          media_type = "image";
        }

        if($(obj).siblings('img').length == 0 && media_type in Drupal.settings.story_map.marker_icons ) {
          $(obj).before('<img src="' + Drupal.settings.story_map.marker_icons[media_type]  + '"/>');
        }
      });

      /***********************************
        Move the AddToAny Share buttons
        after the Filter Accordions
      ************************************/
      if($('.view-story-city .view-footer').length) {
        $('.view-story-city .view-filters').after('<div class="addtoany-wrapper">' + $('.view-story-city .view-footer')[0].innerHTML + '</div>');
        $('.view-story-city .view-footer').remove();
      }

      /***********************************
        Opens the Format Filter by default
      ************************************/
      if($('.views-widget-filter-format').length) {
        $('.views-widget-filter-format').find('details').attr('open', true);
      }
    }
  }

  /******************************************************************
    Clear Query Data from URL
  ******************************************************************/
  function clearQueryData(map, new_url) {
    if(new_url === undefined) {
      new_url = "";
    }
      if(new_url) {
      starting_url = new_url;
    } else {
      starting_url = document.location.href;
    }

    //PID
    if(document.location.href.match(pid_regex)) {
      new_url = starting_url.replace(pid_regex, "");
    }

    //Zoom
    if(document.location.href.match(zoom_regex)) {
      new_url = new_url.replace(zoom_regex, "");
    }

    //Cluster
    if(document.location.href.match(cluster_regex)) {
      new_url = new_url.replace(cluster_regex, "");
      //Reset the map max zoom level
      map.setMaxZoom(17);
    }

    //Latitude
    if(document.location.href.match(lat_regex)) {
      new_url = new_url.replace(lat_regex, "");
    }

    //Longitude
    if(document.location.href.match(lng_regex)) {
      new_url = new_url.replace(lng_regex, "");
    }

    //Replace URL
    history.replaceState(null, null, new_url);
  }

  /******************************************************************
    Lightbox
  ******************************************************************/
  function story_media_lightbox(thumbnail) {
    this.media = '';
    this.media_link = thumbnail.parent('a').attr('href');
    this.media_type = thumbnail.data('storyMediaType');
    this.init = init;

    function init() {
      my_lightbox = this;

      //Make the modal placeholder if it doesn't already exist
      if($('.modal-placeholder').length == 0) {
        $('body').append('<div class="modal-placeholder"></div>');
      }

      // Create the modal markup
      modal_markup =  '<div class="remodal remodal-story-media" data-remodal-id="story-media-modal">';
      modal_markup += '<button data-remodal-action="close" class="remodal-close"></button>';

      modal_markup += '<div class="story-media-wrapper">'
      if(my_lightbox.media_type == "video") {
        modal_markup += '<video controls controlsList="nodownload"> <source src="' + my_lightbox.media_link + '"> Your browser does not support the video element. </video>';
      } else if(my_lightbox.media_type == "image") {
        modal_markup += '<img alt="thumbnail" src="' + my_lightbox.media_link + '">';
      }

      modal_markup += '</div>';

      modal_markup += '</div>';

      //Apply the HTML to the modal placeholder
      $('.modal-placeholder').html(modal_markup);

      //Create and open the modal
      var remodal_options = {
        hashTracking: false
      }
      modal_instance = $('[data-remodal-id=story-media-modal]').remodal(remodal_options);
      modal_instance.open();

      //Destroy the modal when it's closed, so it can re-made later
      $(document).on('closing', '.remodal', function (e) {
        modal_instance.destroy();
      });
    }
  }

  /******************************************************************
    AddToAny
  ******************************************************************/
   // A custom "onShare" handler for AddToAny
  function my_addtoany_onshare(share_data) {

    // Some fragment identifier
    var query_parameters = document.location.search;
    // The shared URL
    var old_url = share_data.url;
    // Initialize new shared URL
    var new_url = old_url;

    // Add fragment identifier if not already added to the shared URL
    if ( old_url.indexOf(query_parameters, old_url.length - query_parameters.length) === -1 ) {
      new_url = old_url + query_parameters;
    }

    // Modify the share by returning an object
    // with a "url" property containing the new URL
    if (new_url != old_url) {
      return {
        url: new_url
      };
    }
  }

  // Setup AddToAny "onShare" callback function
  var a2a_config = a2a_config || {};
  a2a_config.callbacks = a2a_config.callbacks || [];
  a2a_config.callbacks.push({
    share: my_addtoany_onshare
  });
}(jQuery, Drupal));
