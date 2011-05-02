#lang racket/base
(require rackunit/docs-complete)
(check-docs (quote web-server/web-server))
(check-docs (quote web-server/web-server-unit))
(check-docs (quote web-server/web-server-sig))
(check-docs (quote web-server/web-config-unit))
(check-docs (quote web-server/web-config-sig))
(check-docs (quote web-server/templates))
(check-docs (quote web-server/stuffers))
(check-docs (quote web-server/servlet))
(check-docs (quote web-server/servlet-env))
(check-docs (quote web-server/servlet-dispatch))
(check-docs (quote web-server/page))
(check-docs (quote web-server))
(check-docs (quote web-server/http))
(check-docs (quote web-server/formlets))
(check-docs (quote web-server/dispatch))