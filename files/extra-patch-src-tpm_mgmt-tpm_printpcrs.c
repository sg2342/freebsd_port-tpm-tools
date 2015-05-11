--- /dev/null	2015-05-11 00:33:00.000000000 +0000
+++ src/tpm_mgmt/tpm_printpcrs.c	2015-05-11 00:26:31.708522000 +0000
@@ -0,0 +1,61 @@
+/*
+ * The Initial Developer of the Original Code is International
+ * Business Machines Corporation. Portions created by IBM
+ * Corporation are Copyright (C) 2005 International Business
+ * Machines Corporation. All Rights Reserved.
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the Common Public License as published by
+ * IBM Corporation; either version 1 of the License, or (at your option)
+ * any later version.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * Common Public License for more details.
+ *
+ * You should have received a copy of the Common Public License
+ * along with this program; if not, a copy can be viewed at
+ * http://www.opensource.org/licenses/cpl1.0.php.
+ */
+
+#include "tpm_tspi.h"
+#include "tpm_utils.h"
+
+TSS_HCONTEXT hContext = 0;
+
+int main(int argc, char **argv) 
+{
+	TSS_HTPM hTpm;
+	BYTE *rgbPcrValue;
+	UINT32 ulPcrValueLength=20;
+	int i;
+	UINT32 j;
+	int iRc = 1;
+
+	if (contextCreate(&hContext) != TSS_SUCCESS)
+		goto out;
+
+	if (contextConnect(hContext) != TSS_SUCCESS)
+		goto out_close;
+
+	if (contextGetTpm(hContext, &hTpm) != TSS_SUCCESS)
+		goto out_close;
+
+	for (j=0; j<24; ++j) {
+		if (Tspi_TPM_PcrRead(hTpm, j, &ulPcrValueLength, &rgbPcrValue) != TSS_SUCCESS)
+			break;
+
+		printf("PCR %02d ", j);
+		for (i=0; i<19; ++i)
+			printf("%02x",*(rgbPcrValue+i));
+		printf("\n");
+	}
+	iRc = 0;
+
+      out_close:
+	contextClose(hContext);
+
+      out:
+	return iRc;
+}
