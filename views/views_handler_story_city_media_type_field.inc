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
 * @ingroup views_field_handlersI
 */
class views_handler_story_city_media_type_field extends views_handler_field {

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
      // Determine media type
      if(!empty($value->fedora_datastream_info_PROXY_MP3_ID_ms)) {
        $value->story_city_media_type_field = 'audio';
      } elseif(!empty($value->fedora_datastream_version_MP4_ID_ms)) {
        $value->story_city_media_type_field = 'video';
      } else {
        $value->story_city_media_type_field = 'image';
      }
    }
  }
  function render($values) {
    if(!empty($values->story_city_media_type_field)) {
      return $values->story_city_media_type_field;
    } else {
      return NULL;
    }
  }
}
