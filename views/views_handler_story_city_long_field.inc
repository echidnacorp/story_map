<?php

/**
 * @file
 * Custom views handler definition.
 *
 * Place this code in
 * /sites/all/[custom_module_name]/includes/views_handler_my_custom_field.inc
 */

/**
 * Custom handler class.
 *
 * @ingroup views_field_handlers
 */
class views_handler_story_city_long_field extends views_handler_field {
  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function pre_render(&$values) {
    foreach ($values as $key => $value) {
      if(!empty($value->mods_subject_cartographics_coordinates_s)){
        $latlon_array = explode(',', preg_replace('/(\d{1,8}),(\d{1,8})/', '$1.$2', $value->mods_subject_cartographics_coordinates_s));
        if(array_key_exists(1, $latlon_array)) {
          $value->story_map_story_city_long_field = floatval($latlon_array[1]);
        }
        else {
          $value->story_map_story_city_long_field = NULL;
        }
      }
      else {
        $value->story_map_story_city_long_field = NULL;
      }
    }
  }

  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    if(!empty($values->story_map_story_city_long_field)){
      if($values->story_map_story_city_long_field == NULL || $values->story_map_story_city_long_field == 0){
        return NULL;
      }
      return $values->story_map_story_city_long_field;
    }
    else {
      return NULL;
    }
  }
}
