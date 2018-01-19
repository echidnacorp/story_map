<?php
/**
 * @file
 * story_map_views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function story_map_views_default_views() {
  // begin export from Views
  $view = new view();
  $view->name = 'story_city';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'islandora_solr';
  $view->human_name = 'Story City';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Story City';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'neighbourhood' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'community' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'time_period' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'language' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'format' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'ip_geoloc_leaflet';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="a2a_kit a2a_kit_size_32 a2a_default_style">
  <a class="a2a_button_facebook"></a>
  <a class="a2a_button_twitter"></a>
  <a class="a2a_button_email"></a>
  <a class="a2a_dd" href="https://www.addtoany.com/share"></a>
  </div>';
  /* Field: PID (Hidden) */
  $handler->display->display_options['fields']['PID']['id'] = 'PID';
  $handler->display->display_options['fields']['PID']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['PID']['field'] = 'PID';
  $handler->display->display_options['fields']['PID']['ui_name'] = 'PID (Hidden)';
  $handler->display->display_options['fields']['PID']['label'] = '';
  $handler->display->display_options['fields']['PID']['exclude'] = TRUE;
  $handler->display->display_options['fields']['PID']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['PID']['link_to_object'] = 0;
  /* Field: Media: Thumbnail Image (Hidden) */
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['id'] = 'fedora_datastream_latest_TN_MIMETYPE_ms';
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['field'] = 'fedora_datastream_latest_TN_MIMETYPE_ms';
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['ui_name'] = 'Media: Thumbnail Image (Hidden)';
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['label'] = '';
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['alter']['text'] = '<img alt="thumbnail" src="/islandora/object/[PID]/datastream/TN/view">';
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['alter']['path'] = '/islandora/object/[PID]';
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_latest_TN_MIMETYPE_ms']['link_to_object'] = 0;
  /* Field: Media: Audio (Hidden) */
  $handler->display->display_options['fields']['fedora_datastream_info_PROXY_MP3_ID_ms']['id'] = 'fedora_datastream_info_PROXY_MP3_ID_ms';
  $handler->display->display_options['fields']['fedora_datastream_info_PROXY_MP3_ID_ms']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['fedora_datastream_info_PROXY_MP3_ID_ms']['field'] = 'fedora_datastream_info_PROXY_MP3_ID_ms';
  $handler->display->display_options['fields']['fedora_datastream_info_PROXY_MP3_ID_ms']['ui_name'] = 'Media: Audio (Hidden)';
  $handler->display->display_options['fields']['fedora_datastream_info_PROXY_MP3_ID_ms']['label'] = '';
  $handler->display->display_options['fields']['fedora_datastream_info_PROXY_MP3_ID_ms']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_info_PROXY_MP3_ID_ms']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fedora_datastream_info_PROXY_MP3_ID_ms']['link_to_object'] = 0;
  /* Field: Media: Video (Hidden) */
  $handler->display->display_options['fields']['fedora_datastream_version_MP4_ID_ms']['id'] = 'fedora_datastream_version_MP4_ID_ms';
  $handler->display->display_options['fields']['fedora_datastream_version_MP4_ID_ms']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['fedora_datastream_version_MP4_ID_ms']['field'] = 'fedora_datastream_version_MP4_ID_ms';
  $handler->display->display_options['fields']['fedora_datastream_version_MP4_ID_ms']['ui_name'] = 'Media: Video (Hidden)';
  $handler->display->display_options['fields']['fedora_datastream_version_MP4_ID_ms']['label'] = '';
  $handler->display->display_options['fields']['fedora_datastream_version_MP4_ID_ms']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_version_MP4_ID_ms']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fedora_datastream_version_MP4_ID_ms']['link_to_object'] = 0;
  /* Field: Media: Mime type (Hidden) */
  $handler->display->display_options['fields']['fedora_datastream_version_OBJ_MIMETYPE_ms']['id'] = 'fedora_datastream_version_OBJ_MIMETYPE_ms';
  $handler->display->display_options['fields']['fedora_datastream_version_OBJ_MIMETYPE_ms']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['fedora_datastream_version_OBJ_MIMETYPE_ms']['field'] = 'fedora_datastream_version_OBJ_MIMETYPE_ms';
  $handler->display->display_options['fields']['fedora_datastream_version_OBJ_MIMETYPE_ms']['ui_name'] = 'Media: Mime type (Hidden)';
  $handler->display->display_options['fields']['fedora_datastream_version_OBJ_MIMETYPE_ms']['label'] = '';
  $handler->display->display_options['fields']['fedora_datastream_version_OBJ_MIMETYPE_ms']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fedora_datastream_version_OBJ_MIMETYPE_ms']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fedora_datastream_version_OBJ_MIMETYPE_ms']['link_to_object'] = 0;
  /* Field: Story City: Media Type (Hidden) */
  $handler->display->display_options['fields']['story_city_media_type_field']['id'] = 'story_city_media_type_field';
  $handler->display->display_options['fields']['story_city_media_type_field']['table'] = 'story_map';
  $handler->display->display_options['fields']['story_city_media_type_field']['field'] = 'story_city_media_type_field';
  $handler->display->display_options['fields']['story_city_media_type_field']['ui_name'] = 'Story City: Media Type (Hidden)';
  $handler->display->display_options['fields']['story_city_media_type_field']['label'] = '';
  $handler->display->display_options['fields']['story_city_media_type_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['story_city_media_type_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['story_city_media_type_field']['element_default_classes'] = FALSE;
  /* Field: Story City: Media */
  $handler->display->display_options['fields']['story_city_media_field']['id'] = 'story_city_media_field';
  $handler->display->display_options['fields']['story_city_media_field']['table'] = 'story_map';
  $handler->display->display_options['fields']['story_city_media_field']['field'] = 'story_city_media_field';
  $handler->display->display_options['fields']['story_city_media_field']['label'] = '';
  $handler->display->display_options['fields']['story_city_media_field']['element_label_colon'] = FALSE;
  /* Field: Story City: Title */
  $handler->display->display_options['fields']['mods_titleInfo_title_s']['id'] = 'mods_titleInfo_title_s';
  $handler->display->display_options['fields']['mods_titleInfo_title_s']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['mods_titleInfo_title_s']['field'] = 'mods_titleInfo_title_s';
  $handler->display->display_options['fields']['mods_titleInfo_title_s']['ui_name'] = 'Story City: Title';
  $handler->display->display_options['fields']['mods_titleInfo_title_s']['label'] = '';
  $handler->display->display_options['fields']['mods_titleInfo_title_s']['element_type'] = 'h4';
  $handler->display->display_options['fields']['mods_titleInfo_title_s']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mods_titleInfo_title_s']['link_to_object'] = 0;
  /* Field: Story City: Date */
  $handler->display->display_options['fields']['mods_subject_temporal_s']['id'] = 'mods_subject_temporal_s';
  $handler->display->display_options['fields']['mods_subject_temporal_s']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['mods_subject_temporal_s']['field'] = 'mods_subject_temporal_s';
  $handler->display->display_options['fields']['mods_subject_temporal_s']['ui_name'] = 'Story City: Date';
  $handler->display->display_options['fields']['mods_subject_temporal_s']['label'] = '';
  $handler->display->display_options['fields']['mods_subject_temporal_s']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mods_subject_temporal_s']['link_to_object'] = 0;
  /* Field: Story City: Location */
  $handler->display->display_options['fields']['mods_subject_geographic_s']['id'] = 'mods_subject_geographic_s';
  $handler->display->display_options['fields']['mods_subject_geographic_s']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['mods_subject_geographic_s']['field'] = 'mods_subject_geographic_s';
  $handler->display->display_options['fields']['mods_subject_geographic_s']['ui_name'] = 'Story City: Location';
  $handler->display->display_options['fields']['mods_subject_geographic_s']['label'] = '';
  $handler->display->display_options['fields']['mods_subject_geographic_s']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mods_subject_geographic_s']['link_to_object'] = 0;
  /* Field: Story City: Language */
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['id'] = 'mods_language_languageTerm_code_s';
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['field'] = 'mods_language_languageTerm_code_s';
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['ui_name'] = 'Story City: Language';
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['label'] = '';
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['alter']['text'] = 'Language: [mods_language_languageTerm_code_s]<br>';
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mods_language_languageTerm_code_s']['link_to_object'] = 0;
  /* Field: Custom: Link to Content */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Custom: Link to Content';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="story-media-read-more" href="/islandora/object/[PID]" target="_blank">See full story</a>';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Custom: Download */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Custom: Download';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<a class="story-media-download" href="/islandora/object/[PID]/datastream/OBJ/download">Download</a>';
  $handler->display->display_options['fields']['nothing_2']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Map: Latitude (Hidden) */
  $handler->display->display_options['fields']['story_city_lat_field']['id'] = 'story_city_lat_field';
  $handler->display->display_options['fields']['story_city_lat_field']['table'] = 'story_map';
  $handler->display->display_options['fields']['story_city_lat_field']['field'] = 'story_city_lat_field';
  $handler->display->display_options['fields']['story_city_lat_field']['ui_name'] = 'Map: Latitude (Hidden)';
  $handler->display->display_options['fields']['story_city_lat_field']['label'] = '';
  $handler->display->display_options['fields']['story_city_lat_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['story_city_lat_field']['element_label_colon'] = FALSE;
  /* Field: Map: Longitude (Hidden) */
  $handler->display->display_options['fields']['story_city_long_field']['id'] = 'story_city_long_field';
  $handler->display->display_options['fields']['story_city_long_field']['table'] = 'story_map';
  $handler->display->display_options['fields']['story_city_long_field']['field'] = 'story_city_long_field';
  $handler->display->display_options['fields']['story_city_long_field']['ui_name'] = 'Map: Longitude (Hidden)';
  $handler->display->display_options['fields']['story_city_long_field']['label'] = '';
  $handler->display->display_options['fields']['story_city_long_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['story_city_long_field']['element_label_colon'] = FALSE;
  /* Field: Map: Coordinates (Hidden) */
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['id'] = 'mods_subject_cartographics_coordinates_s';
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['table'] = 'islandora_solr';
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['field'] = 'mods_subject_cartographics_coordinates_s';
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['ui_name'] = 'Map: Coordinates (Hidden)';
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['label'] = '';
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['mods_subject_cartographics_coordinates_s']['link_to_object'] = 0;
  /* Field: Map: Marker Differentiator (Hidden) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Map: Marker Differentiator (Hidden)';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[story_city_media_type_field]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );

  /* Display: Story City */
  $handler = $view->new_display('page', 'Story City', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ip_geoloc_leaflet';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => '',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['map'] = 'esri-world_street_map';
  $handler->display->display_options['style_options']['map_height'] = '80vh';
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = array(
    'story_map_story_city_lat_field' => 'story_map_story_city_lat_field',
  );
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = 'story_map_story_city_long_field';
  $handler->display->display_options['style_options']['visitor_marker']['visitor_marker_accuracy_circle'] = 0;
  $handler->display->display_options['style_options']['differentiator']['differentiator_field'] = 'views_nothing_1';
  $handler->display->display_options['style_options']['center_option'] = '4';
  $handler->display->display_options['style_options']['tags']['marker_tag'] = 'PID';
  $handler->display->display_options['style_options']['tags']['tag_css_class'] = 'leaflet-interactive leatlet-zoom-animated';
  $handler->display->display_options['style_options']['sync']['2'] = 0;
  $handler->display->display_options['style_options']['sync']['4'] = 0;
  $handler->display->display_options['style_options']['sync']['8'] = 1;
  $handler->display->display_options['style_options']['sync']['16'] = 1;
  $handler->display->display_options['style_options']['full_screen'] = 0;
  $handler->display->display_options['style_options']['scale_metric'] = 1;
  $handler->display->display_options['style_options']['scale_imperial'] = 0;
  $handler->display->display_options['style_options']['zoom_indicator'] = 0;
  $handler->display->display_options['style_options']['open_balloons_on_click'] = 1;
  $handler->display->display_options['style_options']['open_balloons_on_hover'] = 0;
  $handler->display->display_options['style_options']['goto_content_on_click'] = 0;
  $handler->display->display_options['style_options']['map_reset'] = 0;
  $handler->display->display_options['style_options']['map_cluster_toggle'] = 0;
  $handler->display->display_options['style_options']['mini_map']['on'] = 0;
  $handler->display->display_options['style_options']['mini_map']['height'] = '100';
  $handler->display->display_options['style_options']['mini_map']['width'] = '150';
  $handler->display->display_options['style_options']['mini_map']['toggle'] = 1;
  $handler->display->display_options['style_options']['mini_map']['zoom_delta'] = '-5';
  $handler->display->display_options['style_options']['cluster_radius'] = '60';
  $handler->display->display_options['style_options']['disable_clustering_at_zoom'] = '18';
  $handler->display->display_options['style_options']['cluster_differentiator']['cluster_differentiator_fields'] = array(
    '' => '',
  );
  $handler->display->display_options['style_options']['cluster_differentiator']['zoom_ranges'] = array(
    1 => '',
  );
  $handler->display->display_options['style_options']['cluster_differentiator']['cluster_tooltips'] = 1;
  $handler->display->display_options['style_options']['cluster_differentiator']['cluster_outline'] = '0';
  $handler->display->display_options['style_options']['cluster_differentiator']['cluster_touch_mode'] = '1';
  $handler->display->display_options['style_options']['cluster_aggregation']['aggregation_function'] = 'average';
  $handler->display->display_options['style_options']['cluster_aggregation']['ranges']['small'] = '10';
  $handler->display->display_options['style_options']['cluster_aggregation']['ranges']['medium'] = '100';
  $handler->display->display_options['style_options']['cluster_aggregation']['ranges']['large'] = '1000';
  $handler->display->display_options['style_options']['empty_map_center'] = 'visitor';
  $handler->display->display_options['style_options']['map_options']['maxzoom'] = '18';
  $handler->display->display_options['style_options']['map_options']['zoom'] = '12';
  $handler->display->display_options['style_options']['map_options']['scrollwheelzoom'] = '1';
  $handler->display->display_options['style_options']['map_options']['dragging'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Islandora Solr: Story City Neighbourhood */
  $handler->display->display_options['filters']['neighbourhood']['id'] = 'neighbourhood';
  $handler->display->display_options['filters']['neighbourhood']['table'] = 'islandora_solr';
  $handler->display->display_options['filters']['neighbourhood']['field'] = 'neighbourhood';
  $handler->display->display_options['filters']['neighbourhood']['group'] = 1;
  $handler->display->display_options['filters']['neighbourhood']['exposed'] = TRUE;
  $handler->display->display_options['filters']['neighbourhood']['expose']['operator_id'] = 'neighbourhood_op';
  $handler->display->display_options['filters']['neighbourhood']['expose']['label'] = 'Neighbourhoods';
  $handler->display->display_options['filters']['neighbourhood']['expose']['operator'] = 'neighbourhood_op';
  $handler->display->display_options['filters']['neighbourhood']['expose']['identifier'] = 'neighbourhood';
  $handler->display->display_options['filters']['neighbourhood']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['neighbourhood']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Islandora Solr: Story City Community */
  $handler->display->display_options['filters']['community']['id'] = 'community';
  $handler->display->display_options['filters']['community']['table'] = 'islandora_solr';
  $handler->display->display_options['filters']['community']['field'] = 'community';
  $handler->display->display_options['filters']['community']['group'] = 1;
  $handler->display->display_options['filters']['community']['exposed'] = TRUE;
  $handler->display->display_options['filters']['community']['expose']['operator_id'] = 'community_op';
  $handler->display->display_options['filters']['community']['expose']['label'] = 'Community';
  $handler->display->display_options['filters']['community']['expose']['operator'] = 'community_op';
  $handler->display->display_options['filters']['community']['expose']['identifier'] = 'community';
  $handler->display->display_options['filters']['community']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['community']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Islandora Solr: Story City Time Period */
  $handler->display->display_options['filters']['time_period']['id'] = 'time_period';
  $handler->display->display_options['filters']['time_period']['table'] = 'islandora_solr';
  $handler->display->display_options['filters']['time_period']['field'] = 'time_period';
  $handler->display->display_options['filters']['time_period']['group'] = 1;
  $handler->display->display_options['filters']['time_period']['exposed'] = TRUE;
  $handler->display->display_options['filters']['time_period']['expose']['operator_id'] = 'time_period_op';
  $handler->display->display_options['filters']['time_period']['expose']['label'] = 'Time Period';
  $handler->display->display_options['filters']['time_period']['expose']['operator'] = 'time_period_op';
  $handler->display->display_options['filters']['time_period']['expose']['identifier'] = 'time_period';
  $handler->display->display_options['filters']['time_period']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['time_period']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Islandora Solr: Story City Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'islandora_solr';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Islandora Solr: Collection (uri_s) */
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_s']['id'] = 'RELS_EXT_isMemberOfCollection_uri_s';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_s']['table'] = 'islandora_solr';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_s']['field'] = 'RELS_EXT_isMemberOfCollection_uri_s';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_s']['ui_name'] = 'Islandora Solr: Collection (uri_s)';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_s']['value'] = 'info:fedora/islandora:story_city_collection';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_s']['group'] = 2;
  /* Filter criterion: Islandora Solr: Collection (uri_ms) */
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_ms']['id'] = 'RELS_EXT_isMemberOfCollection_uri_ms';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_ms']['table'] = 'islandora_solr';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_ms']['field'] = 'RELS_EXT_isMemberOfCollection_uri_ms';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_ms']['ui_name'] = 'Islandora Solr: Collection (uri_ms)';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_ms']['value'] = 'info:fedora/islandora:story_city_collection';
  $handler->display->display_options['filters']['RELS_EXT_isMemberOfCollection_uri_ms']['group'] = 2;
  /* Filter criterion: Islandora Solr: Story City Format */
  $handler->display->display_options['filters']['format']['id'] = 'format';
  $handler->display->display_options['filters']['format']['table'] = 'islandora_solr';
  $handler->display->display_options['filters']['format']['field'] = 'format';
  $handler->display->display_options['filters']['format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['format']['expose']['operator_id'] = 'format_op';
  $handler->display->display_options['filters']['format']['expose']['label'] = 'Format';
  $handler->display->display_options['filters']['format']['expose']['operator'] = 'format_op';
  $handler->display->display_options['filters']['format']['expose']['identifier'] = 'format';
  $handler->display->display_options['filters']['format']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['format']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'story-city';

  // end export from Views

  $views[$view->name] = $view;
  // return views
  return $views;
}
