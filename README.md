# story_map

This module was developed by Digital Echidna for the Vancouver Public Library's Story City project.
It builds a map with clickable "Story Pins" whose locations are pulled from Location fields within Objects in Islandora.  

Clicking a Story Pin will open a little popup that displays an Image, Audio clip, or Video with a short description.  This data is also pulled from Islandora Objects.

![Story City](https://github.com/echidnacorp/story_map/blob/master/example.png)

A working example can be seen here: http://thisvancouver.vpl.ca/story-city


### Additional Required modules and libraries
- AddToAny module https://www.drupal.org/project/addtoany
- Views AJAX History https://www.drupal.org/project/views_ajax_history (pretty much a wrapper around History.js)
- Leaflet: https://www.drupal.org/project/leaflet 
- Leaflet Marker Cluster: https://www.drupal.org/project/leaflet_markercluster 
- Leaflet More Maps: https://www.drupal.org/project/leaflet_more_maps 
- Leaflet Plugins: https://www.drupal.org/project/leaflet_plugins 
- Leaflet Hash: https://www.drupal.org/project/leaflet_hash 
- IP Geolocation Views: https://www.drupal.org/project/ip_geoloc 
- AddToAny:  https://www.drupal.org/project/addtoany 

### Libraries
- history.js https://github.com/browserstate/history.js/
- leaflet-plugins https://github.com/shramov/leaflet-plugins
- Remodal: https://github.com/vodkabears/Remodal 


## Installation
- Enable and configure the modules listed above.  
- Enable the story_map module.  
- Go to the view settings for Story City.  /admin/structure/views/view/story_city/edit 
- Modify the field settings, and enter the Solr machine names for the fields you wish to pull.  Remove the fields that don’t apply to your Islandora installation.
- Modify the filter settings, and enter the Solr machine names for the fields you want to filter by.  
- To start, just use the bare minimum filters, and fields so that you’re able to see some results.

### Custom Template and CSS
Out of the box, there is a template that can be applied to pages that have the map.  You can re-enable it if you want to use a different template, or have different theming applied to the map.
In  vpl_story_city_preprocess_page() (vpl_story_city/vpl_story_city.module:346) - we’ve commented out our code that determines if the page has a map on it, and causes Drupal to use our module specific template.  You could uncomment it, and modify the conditions to better suit your site.
This should also be done here: 
- vpl_story_city_preprocess_html() (vpl_story_city.module: 364:)
- vpl_story_city_theme_registry_alter() (vpl_story_city.module:373 )

### Additional Configuration Options
Additional Configuration options are outlined here in the link below.  Keep in mind, the module is called vpl_story_city in this documentation.
https://docs.google.com/document/d/15ShkhdjPQBWeqihlaJY2DhHFmF1CniBsJzL1VuTRpfU/edit?usp=sharing 
