RESOURCES_LIBRARY() 
 
OWNER(g:contrib heretic) 
 
IF (OS_LINUX) 
    DECLARE_EXTERNAL_RESOURCE(STD_TREE sbr:1094784663) 
ELSE() 
    MESSAGE(FATAL_ERROR "No stdc++ tree part for the selected platform found") 
ENDIF() 
LDFLAGS("-L$STD_TREE_RESOURCE_GLOBAL") 
EXTRALIBS(tree) 
 
END() 
