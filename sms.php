<?php
/**
 * PHP-cli script for sending free SMS via Eurobate
 * Inspired by http://github.com/voldern/sms/tree/master
 *
 * By: Alexander Karlstad
 */


class SMS {
    public static function send($from, $to, $msg) {
        $msg = trim($msg);

        $msg = (string) iconv('utf8', 'iso88591', $msg);
        $msg = urlencode($msg);

        $url = 'http://eurobate.com/index.php';
        $url = parse_url($url);

        $q = 'countrylist=47&gsm=%s&melding=%s&';
        $q .= 'option=com_gratissms&task=send&usr_gsm=%s';
        $q = sprintf($q, $to, $msg, $from);

        $sock = fsockopen($url['host'], 80, $errno, $errstr, 5);
        socket_set_timeout($sock, 5);

        if ($sock !== FALSE) {
            $post = "POST {$url['path']}?{$q} HTTP/1.1\r\nHost: {$url['host']}\r\n\r\n";
            $res = fwrite($sock, $post);
            if (is_int($res)) {
                fclose($sock);
                return TRUE;
            }
        }
        fclose($sock);
        return FALSE;
    }
}
