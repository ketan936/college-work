#include <gtk/gtk.h>

typedef struct _Data Data;
struct _Data
{
    GtkWidget *up;   /* Up button */
    GtkWidget *down; /* Down button */
    GtkWidget *tree; /* Tree view */
};


G_MODULE_EXPORT void
cb_move( GtkWidget *button,
         Data      *data )
{
    gboolean          direction = TRUE; /* TRUE means "move up", FALSE "move down" */
    GList            *rows, *tmp;       /* List of selected row */
    GtkTreeModel     *model;            /* Model with data, which we'll be moving. */
    GtkTreeSelection *sel = gtk_tree_view_get_selection( GTK_TREE_VIEW( data->tree ) );

    /* If nothing is selected, return. */
    if( ! gtk_tree_selection_count_selected_rows( sel ) )
        return;

    /* In which direction we'll be moving? */
    if( button == data->down )
        direction = FALSE;

    /* Get selected rows */
    rows = gtk_tree_selection_get_selected_rows( sel, &model );

    /* Get new path for each selected row and swap items. */
    for( tmp = rows; tmp; tmp = g_list_next( tmp ) )
    {
        GtkTreePath *path1, *path2; /* Paths. */
        GtkTreeIter  iter1, iter2;  /* Iters for swapping items. */

        /* Copy path */
        path1 = (GtkTreePath *)tmp->data;
        path2 = gtk_tree_path_copy( path1 );

        /* Move path2 in right direction */
        if( direction )
            gtk_tree_path_prev( path2 );
        else
            gtk_tree_path_next( path2 );

        /* Compare paths and skip one iteration if the paths are equal, which means we're
         * trying to move first path up. */
        if( ! gtk_tree_path_compare( path1, path2 ) )
        {
            gtk_tree_path_free( path2 );
            continue;
        }

        /* Now finally obtain iters and swap items. If the second iter is invalid, we're
         * trying to move the last item down. */
        gtk_tree_model_get_iter( model, &iter1, path1 );
        if( ! gtk_tree_model_get_iter( model, &iter2, path2 ) )
        {
            gtk_tree_path_free( path2 );
            continue;
        }
        gtk_list_store_swap( GTK_LIST_STORE( model ), &iter1, &iter2 );
        gtk_tree_path_free( path2 );
    }

    /* Free our paths */
    g_list_foreach( rows, (GFunc)gtk_tree_path_free, NULL );
    g_list_free( rows );
}

int
main( int    argc,
      char **argv )
{
    GtkBuilder *builder;
    GtkWidget  *window;
    Data        data;

    gtk_init( &argc, &argv );

    /* Create builder */
    builder = gtk_builder_new();
    gtk_builder_add_from_file( builder, "treeview.builder", NULL );

    window    = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );
    data.up   = GTK_WIDGET( gtk_builder_get_object( builder, "move_up" ) );
    data.down = GTK_WIDGET( gtk_builder_get_object( builder, "move_down" ) );
    data.tree = GTK_WIDGET( gtk_builder_get_object( builder, "treeview" ) );

    gtk_builder_connect_signals( builder, &data );
    g_object_unref( G_OBJECT( builder ) );

    gtk_widget_show( window );
    gtk_main();

    return( 0 );
}