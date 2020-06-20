<?php
class KopanoServer extends simplePlugin {
    protected $displayHeader = TRUE;
    static function plInfo():
        array {
            return [
                'plShortName' => _('Kopano') , 
                'plDescription' => _('Edit Kopano Server settings') , 
                'plIcon' => 'geticon.php?context=applications&icon=kopano&size=48', 
                'plSmallIcon' => 'geticon.php?context=applications&icon=kopano&size=16', 
                'plObjectClass' => ['kopano-server'], 
                'plObjectType' => ['server'], 
                'plProvidedAcls' => parent::generatePlProvidedAcls(static ::getAttributesInfo())
                 ];
        }
        static function getAttributesInfo():
            array {
                return ['main' => ['name' => _('Kopano Settings') , 'attrs' => [
                    new IntAttribute(_('HTTP Port') , _('Port for the HTTP Connection') , 'kopanoHttpPort', TRUE, 0, 65535, 236) , 
                    new IntAttribute(_('SSL Port') , _('Port for the HTTPS Connection') , 'kopanoSslPort', TRUE, 0, 65535, 237) ,
                    new StringAttribute(_('Socket Path') , _('Unix socket or named pipe to the server') , 'kopanoFilePath', FALSE) ,
                    new BooleanAttribute(_('Public Store') , _('This server contains the public store') , 'kopanoContainsPublic') ,
                    new URLAttribute(_('Proxy URL') , _('Proxy URL for this server') , 'kopanoProxyURL') , ]], ];
            }
        }
?>
