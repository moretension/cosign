#!/usr/local/bin/perl -wT

use strict;

# change 'central' to the url of your central weblogin server.
my $central = "https://weblogin.umich.edu/cgi-bin/logout";
my $query_string = "?http://directory.umich.edu/";

# expire and nullify service cookie
print( "Set-Cookie: cosign-directory=null; path=/; expires=Wednesday, 27-Jan-77 00:00:00 GMT; secure\n" );

if ( $ENV{ QUERY_STRING } =~ m|^(https?://.*)$| ) {
    $query_string = "?$1";
}

# perform any local cleanup here

# redirect to central weblogin server
print( "Location: $central$query_string\n\n" );

exit( 0 );
