--- src/tpm_mgmt/tpm_nvwrite.c
+++ src/tpm_mgmt/tpm_nvwrite.c
@@ -209,21 +209,19 @@
 		fd = open(filename, O_RDONLY);
 		if (fd < 0) {
 			logError(_("Could not open file %s for reading.\n"));
+			free(rgbDataToWrite);
 			return -1;
 		}
 		read_bytes = read(fd, rgbDataToWrite, ulDataLength);
 
 		if (read_bytes < 0 || ulDataLength != (UINT32)read_bytes) {
 			logError(_("Error while reading data.\n"));
+			free(rgbDataToWrite);
 			return -1;
 		}
 		close(fd);
 		fd = -1;
 	} else if (fillvalue >= 0) {
-		if (length < 0) {
-			logError(_("Requiring size parameter.\n"));
-			return -1;
-		}
 		ulDataLength = length;
 		rgbDataToWrite = malloc(ulDataLength);
 		if (rgbDataToWrite == NULL) {
