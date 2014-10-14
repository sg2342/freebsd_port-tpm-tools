# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	tpm-tools
PORTVERSION=	1.3.8
CATEGORIES=	security
MASTER_SITES=	SF/trousers/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Provides a basic set of TPM tools

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtspi.so:${PORTSDIR}/security/trousers
BUILD_DEPENDS=	pkcsconf:${PORTSDIR}/security/opencryptoki
RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:${PORTSDIR}/security/trousers \
		${LOCALBASE}/lib/pkcs11/libopencryptoki.so:${PORTSDIR}/security/opencryptoki

USES=		gettext gmake iconv libtool autoreconf
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
LIBS+=		-L${LOCALBASE}/lib -lintl

#post-patch:
#	@${REINPLACE_CMD} '/^libtpm_unseal_la_LIBADD =/s/$$/ -lcrypto/' \
#		${WRKSRC}/lib/Makefile.in


.include <bsd.port.mk>
