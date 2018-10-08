provider "cloudflare" {
  email = "yourEmail@e-g.com"
  token = "api-key-account"
}

variable "domain" {
  default = "e-g.com"
}

resource "cloudflare_record" "www" {
  domain  = "${var.domain}"
  name    = "www"
  value   = "10.10.101.102"
  type    = "A"
  proxied = true
}
