<?php
/**
 * <--- Copyright 2005-2011 de Solis - Cooperativa de Soluções Livres Ltda. e
 * Univates - Centro Universitário.
 * 
 * Este arquivo é parte do programa Gnuteca.
 * 
 * O Gnuteca é um software livre; você pode redistribuí-lo e/ou modificá-lo
 * dentro dos termos da Licença Pública Geral GNU como publicada pela Fundação
 * do Software Livre (FSF); na versão 2 da Licença.
 * 
 * Este programa é distribuído na esperança que possa ser útil, mas SEM
 * NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO a qualquer MERCADO
 * ou APLICAÇÃO EM PARTICULAR. Veja a Licença Pública Geral GNU/GPL em
 * português para maiores detalhes.
 * 
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU, sob o título
 * "LICENCA.txt", junto com este programa, se não, acesse o Portal do Software
 * Público Brasileiro no endereço www.softwarepublico.gov.br ou escreva para a
 * Fundação do Software Livre (FSF) Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA --->
 * 
 *  Teste unitário
 *
 * @author Eduardo Bonfandini [eduardo@solis.coop.br]
 *
 * @version $id$
 *
 * \b Maintainers: \n
 * Eduardo Bonfandini [eduardo@solis.coop.br]
 * Jader Osvino Fiegenbaum [jader@solis.coop.br]
 *
 * @since
 * Creation date 03/11/2011
 *
 **/
include_once '../classes/GBusinessUnitTest.class.php';
class TestOperatorLibraryUnit extends GBusinessUnitTest
{
    public function setUp()
    {
        parent::setUp('OperatorLibraryUnit');
        
        $data = new stdClass();
        $data->fullname = $data->fullnameS = 'empy';
        $data->username = $data->usernameS = 'emprt';
        $data->operator = $data->operatorS = '';
        $data->password = $data->passwordS = 'emp';
        $data->groupId = $data->groupIdS = '1000';
        $data->libraryUnitId = $data->libraryUnitIdS = '1';
        $data->libraryName = $data->libraryNameS = '';
        $data->isModified = $data->isModifiedS = 't';
        $data->functionMode = $data->functionModeS = 'manage';
        $data->group = $data->groupS = array (  0 =>   stdClass::__set_state(array(     'module' => 'gnuteca3',     'action' => 'main:configuration:operatorlibraryunit',     '__mainForm__EVENTTARGETVALUE' => 'forceAddToTable',     'function' => 'insert',     'fullname' => 'empy',     'username' => 'emprt',     'operator' => '',     'password' => 'emp',     'groupId' => '1000',     'libraryUnitId' => '1',     'libraryName' => '',     'GRepetitiveField' => 'group',     'arrayItemTemp' => NULL,     'keyCode' => '9',     'isModified' => 't',     'functionMode' => 'manage',     'frm4eb2d9538135d_action' => 'http://gnutecatrunk.guilherme/index.php?module=gnuteca3&action=main:configuration:operatorlibraryunit&__mainForm__EVENTTARGETVALUE=tbBtnNew:click&function=insert',     '__mainForm__VIEWSTATE' => '',     '__mainForm__ISPOSTBACK' => 'yes',     '__mainForm__EVENTARGUMENT' => '',     '__FORMSUBMIT' => '__mainForm',     '__ISAJAXCALL' => 'yes',     '__THEMELAYOUT' => 'dynamic',     '__MIOLOTOKENID' => '',     '__ISFILEUPLOAD' => 'no',     '__ISAJAXEVENT' => 'yes',     'cpaint_response_type' => 'json',     'groupDesc' => 'GTC_ROOT',     'insertData' => true,     'arrayItem' => 0,  )),);
        $data->operatorLibrary = $data->operatorLibraryS = array (  0 =>   stdClass::__set_state(array(     'module' => 'gnuteca3',     'action' => 'main:configuration:operatorlibraryunit',     '__mainForm__EVENTTARGETVALUE' => 'forceAddToTable',     'function' => 'insert',     'fullname' => 'empy',     'username' => 'emprt',     'operator' => '',     'password' => 'emp',     'groupId' => '1000',     'libraryUnitId' => '2',     'libraryName' => 'Desenvolvimento',     'GRepetitiveField' => 'operatorLibrary',     'arrayItemTemp' => NULL,     'keyCode' => '9',     'isModified' => 't',     'functionMode' => 'manage',     'frm4eb2d9538135d_action' => 'http://gnutecatrunk.guilherme/index.php?module=gnuteca3&action=main:configuration:operatorlibraryunit&__mainForm__EVENTTARGETVALUE=tbBtnNew:click&function=insert',     '__mainForm__VIEWSTATE' => '',     '__mainForm__ISPOSTBACK' => 'yes',     '__mainForm__EVENTARGUMENT' => '',     '__FORMSUBMIT' => '__mainForm',     '__ISAJAXCALL' => 'yes',     '__THEMELAYOUT' => 'dynamic',     '__MIOLOTOKENID' => '',     '__ISFILEUPLOAD' => 'no',     '__ISAJAXEVENT' => 'yes',     'cpaint_response_type' => 'json',     'insertData' => true,     'arrayItem' => 0,  )),);

        $this->business->setData($data);
    }
}
?>