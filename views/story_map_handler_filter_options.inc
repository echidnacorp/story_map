<?php

/**
 * @file
 * Views filter handler base to extend Islandora Solr Views default filter handler, to provide options
 */

class story_map_handler_filter_options extends views_handler_filter_in_operator {
  /**
   * TODO: implement options callback
   */
  function get_value_options() {
    $this->value_options = _story_map_solr_facet_query($this->real_field);
    return $this->value_options;
// dpm($this);
  }

  function query() {
    if (!empty($this->value)) {
      $value = $this->value;

      module_load_include('inc', 'islandora_solr', 'includes/utilities');
      $value = islandora_solr_lesser_escape($value);

      $field_name = $this->real_field;
      $exclude = isset($this->operator) && $this->operator === '!=';

      if (is_array($value)) {
        $values = array_filter($value);

        // Ensure that some values have been selected.
        if (!empty($values)) {
          $this->query->add_filter($field_name, '(' . implode(' OR ', $values) . ')', $this->options['group'], $exclude);
        }
        return;
      }
      //$this->query->add_filter($field_name, $value, $this->options['group'], $exclude);
    }
  }
}

/**
 * Facet callback function.
 *
 * @param string $field
 *   Machine name of the Solr field to get facet values from.
 */
function _story_map_solr_facet_query($solr_field) {
  module_load_include('inc', 'islandora_solr', 'includes/utilities');
  // Use Solr faceting to get list of names.
  $parsed_url = parse_url(variable_get('islandora_solr_url', 'http://localhost:8080/solr'));
  $solr = new Apache_Solr_Service($parsed_url['host'], $parsed_url['port'], $parsed_url['path']);


  $solr_build = new IslandoraSolrQueryProcessor();
  // Get the actual results.
  $query = "$solr_field:[* TO *] AND ( RELS_EXT_isMemberOfCollection_uri_s:*story_city_collection OR RELS_EXT_isMemberOfCollection_uri_ms:\"islandora:story_city_collect\" )";

  // Set facet parameters.
  $facet_params = array(
    'facet' => 'true',
    'facet.field' => $solr_field,
    'facet.sort' => 'index',
    'facet.mincount' => 1,
    'facet.limit' => variable_get('islandora_solr_facet_pages_facet_limit', 100000),
    'hl' => 'false',
  );

  $request_handler = variable_get('islandora_solr_request_handler', FALSE);
  if ($request_handler) {
    $facet_params['qt'] = $request_handler;
  }

  // Set the facet prefix.
  $prefix = t('ALL');
  // Not sure exactly what the prefix is meant to do. For now, setting the default.
  if ($prefix != t('ALL')) {
    $facet_params['facet.prefix'] = $prefix;
  }
  $solr_build->buildQuery($query, $facet_params);
  $solr_query = ($solr_build->internalSolrQuery) ? $solr_build->internalSolrQuery : $solr_build->solrQuery;
  // Because the IslandoraSolrQueryProcessor stomps on our facet information.
  $solr_build->solrParams = array_replace_recursive($solr_build->solrParams, $facet_params);
  try {
    $solr_build->executeQuery();
    $fields = (array) $solr_build->islandoraSolrResult['facet_counts']['facet_fields'][$solr_field];
  }
  catch (Exception $e) {
    $fields = array();
    drupal_set_message(check_plain(t('Error searching Solr index')) . ' ' . $e->getMessage(), 'error', FALSE);
  }

  // Restructure the results from [facet] => [num_results] into the format we need
  $options = array();
  foreach ($fields as $facet => $num) {
    $options[$facet] = $facet;
//    $options[$facet] = $facet . ' (' . $num . ')';
  }

  return $options;
}
