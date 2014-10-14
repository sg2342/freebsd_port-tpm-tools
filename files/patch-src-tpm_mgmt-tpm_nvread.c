--- src/tpm_mgmt/tpm_nvread.c.orig	2014-03-27 03:50:40.517389068 +0000
+++ src/tpm_mgmt/tpm_nvread.c	2014-03-27 03:51:39.507385414 +0000
@@ -23,6 +23,7 @@
 #include <ctype.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <sys/stat.h>
 
 #include "tpm_nvcommon.h"
 #include "tpm_tspi.h"
