<?php
namespace App;
class RetrieveData
{
	private $url;
	private $result;
	
	function __construct($url){
		$this->url 	= $url;
	}
	
	public function get(){
		$ch = curl_init();
		$url = "";
		curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0);
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
		curl_setopt($ch,CURLOPT_URL,$this->url);
		curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 3);
		curl_setopt($ch, CURLOPT_TIMEOUT, 10);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
		//curl_setopt($ch, CURLOPT_HEADER, true); for return response header
		$server_output = curl_exec($ch);
		if($server_output === false)
	    {
	        echo "\r\nError Number:".curl_errno($ch);
	        echo "\r\nError String:".curl_error($ch);
	        return false;
	    }

		curl_close ($ch);
		return $server_output;

	}

}
