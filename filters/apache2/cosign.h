typedef struct {
    char                *host;
    char                *service;
    char		*siteentry;
    int			public;
    char                *redirect;
    char                *posterror;
    unsigned short      port;
    int                 protect;
    int                 configured;
    struct connlist     *cl;
    SSL_CTX		*ctx;
    char		*cert;
    char		*key;
    char		*cadir;
    char		*filterdb;
    char		*proxydb;
    char		*tkt_prefix;
    int                 http;
    int			proxy;
    int			expiretime;
#ifdef KRB
#ifdef GSS
    int			gss;
#endif /* GSS */
    int			krbtkt;
    int			krb524;
#endif /* KRB */
} cosign_host_config;


struct connlist {
    struct sockaddr_in  conn_sin;
    SNET                *conn_sn;
    struct connlist     *conn_next;
};


int cosign_cookie_valid( cosign_host_config *, char *, struct sinfo *, char * );
int cosign_check_cookie( char *, struct sinfo *, cosign_host_config *, int );
int teardown_conn( struct connlist * );
