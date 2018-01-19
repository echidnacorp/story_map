<?php
/**
 * @file
 * story_map.views.inc
 */

function story_map_views_data_alter(&$data) {
  /***********************************
    Story City: Neighbourhood
  ************************************/
  $data['islandora_solr']['neighbourhood'] = array(
    'real field' => 'mods_subject_hierarchicalGeographic_citySection_s', // name of entity field to which filter applies
    'title' => t('Story City Neighbourhood'),
    'help' => t('Geographic categories for Story City data'),
    'filter' => array(
      'handler' => 'story_map_handler_filter_options',
    ),
  );
  /***********************************
    Story City: Community
  ************************************/
  $data['islandora_solr']['community'] = array(
    'real field' => 'mods_subject_topic_s',
    'title' => t('Story City Community'),
    'help' => t('Communty categories for Story City data'),
    'filter' => array(
      'handler' => 'story_map_handler_filter_options',
    ),
  );
  /***********************************
    Story City: Time Period
  ************************************/
  $data['islandora_solr']['time_period'] = array(
    'real field' => 'mods_subject_temporal_s',
    'title' => t('Story City Time Period'),
    'help' => t('Time period categories for Story City data'),
    'filter' => array(
      'handler' => 'story_map_handler_filter_options',
    ),
  );
  /***********************************
    Story City: Format
  ************************************/
  $data['islandora_solr']['format'] = array(
    'real field' => 'fedora_datastream_version_OBJ_MIMETYPE_ms',
    'title' => t('Story City Format'),
    'help' => t('Format categories for Story City data'),
    'filter' => array(
      'handler' => 'story_map_handler_filter_options',
    ),
  );
  /***********************************
    Story City: Language
  ************************************/
  $data['islandora_solr']['language'] = array(
    'real field' => 'mods_language_languageTerm_code_s',
    'title' => t('Story City Language'),
    'help' => t('Language categories for Story City data'),
    'filter' => array(
      'handler' => 'story_map_handler_filter_options',
    ),
  );
}
