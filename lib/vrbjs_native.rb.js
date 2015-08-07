/* Generated by Opal 0.8.0.rc2 */
(function(Opal) {
  Opal.dynamic_require_severity = "error";
  var self = Opal.top, $scope = Opal, nil = Opal.nil, $breaker = Opal.breaker, $slice = Opal.slice, $module = Opal.module, $klass = Opal.klass;

  Opal.add_stubs(['$new', '$set_native_type', '$native_type', '$allocate', '$send', '$_native=', '$attr_accessor']);
  return (function($base) {
    var self = $module($base, 'VRbJS');

    var def = self.$$proto, $scope = self.$$scope;

    Opal.defs(self, '$Interface', function(n) {
      var self = this, klass = nil;

      klass = $scope.get('Class').$new((($scope.get('VRbJS')).$$scope.get('Object')));
      klass.$set_native_type(n);
      return klass;
    });

    (function($base, $super) {
      function $Object(){};
      var self = $Object = $klass($base, $super, 'Object', $Object);

      var def = self.$$proto, $scope = self.$$scope, TMP_1;

      Opal.defs(self, '$inherited', function(q) {
        var self = this;

        return q.$set_native_type(self.$native_type());
      });

      Opal.defs(self, '$set_native_type', function(t) {
        var self = this;

        return self.native_type = t;
      });

      Opal.defs(self, '$native_type', function() {
        var self = this;
        if (self.native_type == null) self.native_type = nil;

        return self.native_type;
      });

      Opal.defs(self, '$new', function(args) {
        var $a, $b, self = this, ins = nil;

        args = $slice.call(arguments, 0);
        ins = self.$allocate();
        ins.$send("initialize");
        (($a = [self.$native_type().apply(null, args)]), $b = ins, $b['$_native='].apply($b, $a), $a[$a.length-1]);
        return ins;
      });

      Opal.defs(self, '$wrap', TMP_1 = function(n, o) {
        var $a, $b, self = this, $iter = TMP_1.$$p, b = $iter || nil, ins = nil;

        o = $slice.call(arguments, 1);
        TMP_1.$$p = null;
        ins = self.$allocate();
        ins.$send("initialize");
        (($a = [n]), $b = ins, $b['$_native='].apply($b, $a), $a[$a.length-1]);
        return ins;
      });

      return self.$attr_accessor("_native");
    })(self, null);
  })(self)
})(Opal);