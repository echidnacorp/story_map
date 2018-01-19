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
class views_handler_story_city_media_field extends views_handler_field {

   /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function render($values) {
    if(!empty($values->story_city_media_type_field)) {
      $story_city_media_field = '<div class="story-media" data-media-type="' . $values->story_city_media_type_field . '">';

      if($values->story_city_media_type_field == 'audio') {
        $story_city_media_field .= '<audio controls controlsList="nodownload"> <source src="/islandora/object/' . $values->PID . '/datastream/PROXY_MP3/view" type="audio/mpeg"> <source src="/islandora/object/' . $values->PID . '/datastream/PROXY_MP3/view" type="audio/x-wav"> Your browser does not support the audio element. </audio>';
      } elseif($values->story_city_media_type_field == 'video') {
        $story_city_media_field .= '<a href="/islandora/object/' . $values->PID . '/datastream/MP4/view">';
        $story_city_media_field .= '<img data-story-media-type="video" alt="thumbnail" src="/islandora/object/' . $values->PID . '/datastream/TN/view">';
        $story_city_media_field .= '</a>';
      } elseif($values->story_city_media_type_field == 'image') {
        if($values->fedora_datastream_version_OBJ_MIMETYPE_ms[0] == 'image/tiff') {
          $story_city_media_field .= '<a href="/islandora/object/' . $values->PID . '/datastream/JPG/view">';
          $story_city_media_field .= '<img data-story-media-type="image" alt="thumbnail" src="/islandora/object/' . $values->PID . '/datastream/JPG/view">';
        } else {
          $story_city_media_field .= '<a href="/islandora/object/' . $values->PID . '/datastream/MEDIUM_SIZE/view">';
          $story_city_media_field .= '<img data-story-media-type="image" alt="thumbnail" src="/islandora/object/' . $values->PID . '/datastream/MEDIUM_SIZE/view">';
        }

        $story_city_media_field .= '</a>';
      }

      $story_city_media_field .= '</div>';

      return $story_city_media_field;
    } else {
      return NULL;
    }
  }
}
