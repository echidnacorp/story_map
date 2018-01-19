<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path, when linking to the front page. This includes the language domain or prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by modules, intended to be displayed in front of the main title tag that appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by modules, intended to be displayed after the main title tag that appears in the template.
 * - $messages: HTML for status and error messages. Should be displayed prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not comment/reply/12345).
 *
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 *
 * Changelog:
 * 20161128 TP: changed "thisvancouverfour" references to "thisvancouverfive"
 */
?>
<!-- 0.3.0 -->
<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
  <div class="<?php print $container_class; ?>">

<!-- LOGO PANEL -->
		<div class="row">
      <div class="col-sm-5">
        <div class="navbar-header">
          <!-- The site logo can be added here.  -->
    <!-- END LOGO PANEL -->
    <!-- HAMBURGER MENU -->
          <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
              <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
            </button>
          <?php endif; ?>
        </div>
      </div>
  <!-- END HAMBURGER MENU -->

      <div class="navbar-collapse collapse">
        <div class="col-sm-7">
          <div class="row">
            <nav role="navigation" class="pull-right nav navbar-nav">
              <?php
                /* The top right menu bar can be rendered here */
              ?>
            </nav>
          </div>
          <div class="row">
            <div class="pull-right">
              <?php if (!empty($page['top_bar'])): ?>
                <?php hide($page['top_bar']['islandora_solr_simple']); print render($page['top_bar']); ?>
              <?php endif ?>
            </div>
         </div>
      </div>
    </div>
</div>
</div>
</header>

<div class="slide-body container-fluid clearfix">

<div class="mobile-message">
<div class="container">
  <p>Module developed by Digital Echidna with Vancouver Public Library.</p>
<?php
/**
 * This code can be uncommented, to render a basic block's content if you wish
 * for content editors to be able to customize the message above the map.
 */
/*
$mobile_block = module_invoke('block', 'block_view', '5');
print render($mobile_block['content']);
*/
?>
</div>
</div>
    <div class="row">
		<div class="col-sm-12" id="main-content">
            <!-- Write out the breadcrumb -->
			<?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>

            <!-- Write out the full title, including whatever a title prefix is, the title and a title suffix -->
			<?php print render($title_prefix); ?>

            <?php if (!empty($title)): ?>
                <h1 class="page-header"><?php print $title; ?></h1>
            <?php endif; ?>

            <?php print render($title_suffix); ?>

            <!-- CONTENT REGION the content of the page/node/request -->
            <?php print render($page['content']); ?>
        </div><!-- /#main-content -->
    </div><!-- /.row -->
</div><!-- /.container -->

<!-- Add the footer -->
<footer class="page-end">
	<div class="container">
		<?php print render($page['footer']); ?>
    <div class="row">
      <div class="col-xs-12">

      </div>
	<?php endif ?>
    </div>
	</div>
</footer>
<!-- html.tpl.php takes over from here -->
